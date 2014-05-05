#include "Statistics.h"

Statistics::Statistics()
{

}
/**
 * @CopyConstructor for Statistics class
 */
Statistics::Statistics(Statistics &copyMe)
{
	//For each of the relation copy all the related parameters 
	for(map<string, RelationAttribute>::iterator iter = copyMe.statMap.begin(); iter != copyMe.statMap.end(); iter++)
	{
		RelationAttribute table;
		statMap[iter->first] = table;
		statMap[iter->first].partition_number = iter->second.partition_number;
		statMap[iter->first].numtuples = iter->second.numtuples;
		//For each of the relation copy all the attributes.
		for(map<string, int>::iterator it2 = iter->second.AttributeMap.begin(); it2 != iter->second.AttributeMap.end(); it2++)
		{
			statMap[iter->first].AttributeMap[it2->first] = it2->second;
		}

	}
}
Statistics::~Statistics()
{
}
/**
 * @method AddRel to add new relation with number of tuples specified.
 * @param char* pointing to relation name.
 * @param int value for number of tuples in relation.
 *
 */

void Statistics::AddRel(char *relName, int numTuples)
{
	if(relName == NULL)
	{
		cerr<<"Invalid Relation Name"<<endl;
		exit(0);
	}
	if(statMap.find(relName) == statMap.end())
	{
		RelationAttribute table;
		statMap[relName] = table;
		statMap[relName].numtuples = numTuples;
	}
	else
		statMap[relName].numtuples = numTuples;
}
/**
 * @method AddAtt to add attribute to relation specified. 
 * @param relName char* for relation to which attribute needs to be added.
 * @param attName char* for name of the attribute to be added.
 * @param numDistincts int value for number of distinct value in attribute.
 */

void Statistics::AddAtt(char *relName, char *attName, int numDistincts)
{
  if(relName == NULL || attName == NULL || statMap.find(string(relName)) == statMap.end())
  {
      cerr<<"Either relation or Attribute is NULL."<<endl;
      exit(0);
  }
	if(statMap.find(relName) != statMap.end())
	{
		if(statMap[relName].AttributeMap.count(attName) == 0)
			statMap[relName].AttributeMap[attName] = numDistincts;
		else
			statMap[relName].AttributeMap[attName] = numDistincts;
	}
	//if relation did not exist for reverse look up add it for reverse mapping.
	if(attribute_lookup.find(attName)== attribute_lookup.end())
		attribute_lookup[attName] = relName;
	

}
/**
 * @method CopyRel to copy relation from old name to new name and do a deep copy.
 *
 */
void Statistics::CopyRel(char *oldName, char *newName)
{
	if(oldName == NULL || newName == NULL || statMap.find(oldName) == statMap.end())
    {
        cerr<<" Problem with relation name specified."<<endl;
        exit(0);
    }
	if(statMap.find(newName) == statMap.end())
	{
		RelationAttribute table;
		statMap[newName] = table;
		statMap[newName].numtuples =statMap[oldName].numtuples;
		for(map<string, int>::iterator it = statMap[oldName].AttributeMap.begin(); it != statMap[oldName].AttributeMap.end(); it++)
			statMap[newName].AttributeMap[it->first] = it->second;
		
	}

}
/**
 * @method Read to read a Statistics class from file specified.
 * @param fromWhere char* pointing to file for opening for reading.
 */
void Statistics::Read(char *fromWhere)
{
	ifstream infile(fromWhere);
	
	int relation_size = 0;
	int attsize = 0;
	string relation_name;
	string attname;
	int disttuples = 0;
	infile>>relation_size;

	//READ statMap first.
	if(relation_size != 0)
	{
		for(int i=0;i<relation_size;i++)
		{
			RelationAttribute relAtt;
			infile>>relation_name;
			statMap[relation_name] = relAtt;
			infile>>statMap[relation_name].numtuples;
			infile>>statMap[relation_name].partition_number;
			infile>>attsize;
			for(int i=0;i<attsize;i++)
			{
				infile>>attname;
				infile>>disttuples;
				statMap[relation_name].AttributeMap[attname]=disttuples;
			}
		}
	//Initialise JoinMap.
	infile>>relation_size;
	for(int i=0; i<relation_size; i++)
	{
			int id;
			infile>>id;
			vector<string> relationlist;
			JoinMap[id] = relationlist;
			int vectsize = 0;
			infile>>vectsize;
			for(int j=0; j<vectsize; j++)
			{
				string relation_name;
				infile>>relation_name;
				JoinMap[id].push_back(relation_name);
			}
	}

	//Initialise RelationJoinMap
	infile>>relation_size;
		for(int i=0; i<relation_size; i++)
		{
			string tempstring;
			int value = 0;
			infile>>tempstring;
			infile>>value;
			RelationJoinMap[tempstring] = value;
		}
	//Initialise Reverse look up map
	infile>>relation_size;
	for(int i=0; i<relation_size; i++)
	{
			string attributeName;
			string relationName;
			infile>>attributeName;
			infile>>relationName;
			attribute_lookup[attributeName] = relationName;
	}
	}
	infile.close();
}
/**
 * @method Write to write Statistics class to file specified.
 * @param fromWhere char* pointing to file for writting class instance.
 */
void Statistics::Write(char *fromWhere)
{
	ofstream outfile(fromWhere);
	
	//Write statMap.
	outfile<<statMap.size()<<endl;
	for(map<string, RelationAttribute>::iterator it = statMap.begin(); it != statMap.end(); it++)
	{
		outfile<<it->first<<endl;
		outfile<<it->second.numtuples<<endl;
		outfile<<it->second.partition_number<<endl;
		outfile<<it->second.AttributeMap.size()<<endl;
		for(map<string, int>::iterator it2 = it->second.AttributeMap.begin(); it2 != it->second.AttributeMap.end(); it2++){
			outfile<<it2->first<<endl;
			outfile<<it2->second<<endl;
		}
	}
	//write Join Map.
	outfile<<JoinMap.size()<<endl;
	
	for(map<int, vector<string> >::iterator iter = JoinMap.begin(); iter != JoinMap.end(); iter++)
	{
		outfile<<iter->first<<endl;
		outfile<<iter->second.size()<<endl;
		for(vector<string>::iterator it = iter->second.begin(); it != iter->second.end(); it++)
			outfile<<*it<<endl;
	}
	//Write Relation Join Map
	outfile<<RelationJoinMap.size()<<endl;

	for(map<string, int>::iterator it5 = RelationJoinMap.begin(); it5 != RelationJoinMap.end(); it5++)
	{
		outfile<<it5->first<<endl;
		outfile<<it5->second<<endl;
	}
	
	//Write Attribute_lookup
	outfile<<attribute_lookup.size()<<endl;
	
	for(map<string, string>::iterator it6=attribute_lookup.begin(); it6 != attribute_lookup.end(); it6++){
		outfile<<it6->first<<endl;
		outfile<<it6->second<<endl;
	}

	outfile.close();
}
/**
 * @method Apply
 * @param struct AndList
 * @param char*[] array of tables to join.
 * @param int number of tables to join
 */
void  Statistics::Apply(struct AndList *parseTree, char *relNames[], int numToJoin)
{
	bool no_error =true;
	joined_relation_set.clear();
	vector<string> AttsToEstimate;
	if( !isValid(parseTree, relNames, numToJoin,AttsToEstimate) ||!isValidRelPart(parseTree, relNames, numToJoin))
	{
		exit(0);
	}

	
	double numTuples = Estimate(parseTree, relNames, numToJoin);    
	set<string>::iterator it;
	map<string, int>::iterator it2;
	bool partition_exists = false;
	int newID =0;

	for(it = joined_relation_set.begin(); it != joined_relation_set.end(); it++){
		int partition = statMap[*it].partition_number;
		if(partition == 1 )
		{

			partition_exists = true;
			istringstream convert(*it);
			if ( !(convert >> newID) ) 
				newID = 0;
			break;
		}
	}

	if(!partition_exists)
	{
		for(it2 = RelationJoinMap.begin(); it2 != RelationJoinMap.end(); it2++){
			if(newID<it2->second)
				newID = it2->second;
		}
		newID++;


	}

	for(it = joined_relation_set.begin(); it != joined_relation_set.end(); it++){
		int partition = statMap[*it].partition_number;
		if(partition == 0 )
		{
			RelationJoinMap[*it] = newID;
		}
	}
	
	if(JoinMap.count(newID)==0)
	{
		vector<string> tablenames;
		for(it = joined_relation_set.begin(); it != joined_relation_set.end(); it++){

			tablenames.push_back( *it);

		}

		JoinMap[newID]  = tablenames;
	}
	else
	{
		for(it = joined_relation_set.begin(); it != joined_relation_set.end(); it++){
			string temp = string(*it);

			if(!hasdigits(temp))
				JoinMap[newID].push_back(temp);
			else{
				vector<string>::iterator it1;
				int temp1;

				istringstream convert(*it);
				if ( !(convert >> temp1) )
				{ 
					exit(0);
				}

				for(it1 = JoinMap[temp1].begin(); it1 != JoinMap[temp1].end(); it1++){
					vector<string>::iterator tempit;
					vector<string> tempvector;
					for(tempit = JoinMap[newID].begin(); tempit != JoinMap[newID].end(); tempit++){
						
						tempvector.push_back(*tempit);
					}
					string tempstring = *it1;
					JoinMap[newID] = tempvector;
					RelationJoinMap[*it1] = newID;

				}
			}
		}

	}

	map<string, RelationAttribute>::iterator it5;
	set<string>::iterator it3;
	ostringstream convert;
	convert << newID;      
	string newkey = convert.str();
	RelationAttribute table;

	int temppartition;
	for(it3 = joined_relation_set.begin(); it3 != joined_relation_set.end(); it3++){
		int temp;
		statMap[*it3].partition_number = 1;
		map<string, int>::iterator it4;
		for(it4 = statMap[*it3].AttributeMap.begin(); it4 != statMap[*it3].AttributeMap.end(); it4++){
			table.AttributeMap[it4->first] = it4->second;

		}
		RelationAttribute table1;
		statMap[newkey] = table1;
		statMap[newkey].numtuples = (unsigned long int)numTuples;
		statMap[newkey].partition_number = 1;
		for(it4 = table.AttributeMap.begin(); it4 != table.AttributeMap.end(); it4++){
			statMap[newkey].AttributeMap[it4->first] = it4->second;

		}

	}
	
}

bool Statistics::hasdigits(string s)
{
	int j = 0;
	while(j < s.size()){
		if(s[j] >= '0' && s[j] <= '9'){
			return true;
		}
		j++;
	}
	return false;
}

bool Statistics::isValid(struct AndList *parseTree, char *relNames[], int numToJoin,vector<string> &AttsToEstimate)
{
	for(int i=0;i<numToJoin;i++)
	{
		string rname = string(relNames[i]);
		if(statMap.find(rname) == statMap.end())
			return false;

	}
	string tblname;
	string colname;

	AndList* andtree = parseTree;
	while(andtree!=NULL)
	{
		OrList *ortree = andtree->left;
		while(ortree!=NULL)
		{
			ComparisonOp* compOp = ortree->left;
			if(compOp == NULL)
				break;
			int lcode = compOp->left->code;
			string lval = compOp->left->value;
			ostringstream convert;
			convert << lcode;
			string val = convert.str();

			AttsToEstimate.push_back(val);
			AttsToEstimate.push_back(lval);
			ostringstream convert1;
			convert1 << compOp->code;
			val="";
			int opcode = compOp->code;
			val = convert1.str();
			AttsToEstimate.push_back(val);
			if(lcode == NAME)
			{    
				int pos = lval.find(".");
				if(pos!=string::npos)
				{
					tblname = lval.substr(0, pos);
					colname  = lval.substr(pos+1);

				}
				else
				{
					colname = lval;

				}
				
				if(opcode == EQUALS)
				{

					string i=attribute_lookup[colname];
					if(attribute_lookup.count(colname)==0){
						return false;
					}
				}
			}
			int rcode = compOp->right->code;
			string rval = compOp->right->value;
			val="";
			ostringstream convert2;
			convert2 << rcode;
			val = convert2.str();

			AttsToEstimate.push_back(val);
			AttsToEstimate.push_back(rval);
			if(rcode == NAME)
			{   
				int pos = rval.find(".");
				if(pos!=string::npos)
				{
					tblname = rval.substr(0, pos);
					colname  = rval.substr(pos+1);
				}
				else
				{
					colname = rval;

				}
				if(opcode == EQUALS)
				{
					string i=attribute_lookup[colname];
					if(attribute_lookup.count(colname)==0)
					{
						return false;
					}
				}
			}
			if(ortree->rightOr != NULL)
				AttsToEstimate.push_back("OR");
			ortree = ortree->rightOr;

		}
		if(andtree->rightAnd != NULL)
			AttsToEstimate.push_back("AND");
		else
			AttsToEstimate.push_back("END");

		andtree = andtree->rightAnd;
	}
	return true;
}

bool Statistics::isValidRelPart(struct AndList *parseTree, char *relNames[], int numToJoin)
{

	string temp;
	joined_relation_set.clear();
	for(int i=0; i<numToJoin; i++){
		ostringstream convert;   
		string tblname = string(relNames[i]);
		int singleton = statMap[tblname].partition_number;
		if(singleton != 0){
			bool found = false;
			int id = RelationJoinMap[tblname];
			convert << id;      
			temp = convert.str();
			joined_relation_set.insert(temp);
			vector<string>::iterator it;
			for(it = JoinMap[id].begin(); it != JoinMap[id].end(); it++){
				string st1 = *it;
				for(int k = 0; k<numToJoin; k++){
					string st2 = string(relNames[k]);
					if(st1.compare(st2) == 0){
						found = true;
						break;
					}
				}
				if(found == false){
					return false;
				}
			}
		}
		else
		{
			joined_relation_set.insert(tblname);
		}
	}
	return true;
}

double Statistics::Estimate(struct AndList *parseTree, char **relNames, int numToJoin)
{

	double local_estimate =0;
	joined_relation_set.clear();
	set <string> jointableset;
	map<string, EstimateMetaInfo> EstCheck;
	vector<double> estimates;
	vector<string> AttsToEstimate;        
	string prev_parse = "";

	if(!isValid(parseTree, relNames, numToJoin,AttsToEstimate) || !isValidRelPart(parseTree, relNames, numToJoin))
	{
		cerr<<"Either of the relation or Attribute in valid"<<endl;
		exit(0);
	}
	int i=0;
	while(i<AttsToEstimate.size())
	{
		local_estimate =0;
		int codeType1 = atoi(AttsToEstimate.at(i++).c_str());
		string codeVal1 = AttsToEstimate.at(i++);
		int opcode = atoi(AttsToEstimate.at(i++).c_str());
		int codeType2 = atoi(AttsToEstimate.at(i++).c_str());
		string codeVal2 = AttsToEstimate.at(i++);
		string curParse = AttsToEstimate.at(i++);
		string relation1, relation2;
		if(codeType1==NAME)
		{
			int pos = codeVal1.find(".");
			if(pos!=string::npos)
			{
				relation1 = codeVal1.substr(0,pos);
				codeVal1 = codeVal1.substr(pos+1);
				bool found = false;
				for(int i=0; i< numToJoin;i++)
				{
					if(relNames[i] == relation1)
					{
						found = true;
						break;
					}
				}
				if(!found)
					relation1 = attribute_lookup[codeVal1];
			}
			else
			{
				relation1 = attribute_lookup[codeVal1];
			}
			if(relation1.size()!=0)
				jointableset.insert(relation1);
		}
		if(codeType2==NAME)
		{
			int pos = codeVal2.find(".");
			if(pos!=string::npos)
			{
				relation2 = codeVal2.substr(0,pos);
				codeVal2 = codeVal2.substr(pos+1);
				codeVal1 = codeVal1.substr(pos+1);
				bool found = false;
				for(int i=0; i< numToJoin;i++)
				{
					if(relNames[i] == relation2)
					{
						found = true;
						break;
					}

				}
				if(!found)
					relation2 = attribute_lookup[codeVal2];


			}
			else
			{
				relation2 = attribute_lookup[codeVal2];
			}
			if(relation2.size()!=0)
				jointableset.insert(relation2);
		}
		if(codeType1==NAME && codeType2 == NAME)
		{
			double  maxval = max(statMap[relation1].AttributeMap[codeVal1],statMap[relation2].AttributeMap[codeVal2]);

			local_estimate = 1.0/maxval;
			estimates.push_back(local_estimate);
		}
		else if(codeType1==NAME || codeType2 == NAME)
		{
			string attribute;
			RelationAttribute tableinfo;
			if(codeType1 == NAME)
			{
				tableinfo = statMap[relation1];
				attribute = codeVal1;
			}
			else
			{
				tableinfo = statMap[relation2];
				attribute = codeVal2;
			}
			if(opcode == EQUALS)
			{
				if(curParse == "OR" || prev_parse=="OR")		
				{
					if(EstCheck.find(attribute + "EQ") == EstCheck.end())
					{
						EstimateMetaInfo *est = new EstimateMetaInfo();
						local_estimate = (1.0- 1.0/tableinfo.AttributeMap[attribute]);
						est->attributeCount = 1;
						est->estimatedtuples = local_estimate;
						EstCheck[attribute + "EQ"] = *est;
					}
					else
					{
						local_estimate = 1.0/tableinfo.AttributeMap[attribute];
						EstimateMetaInfo *est = &(EstCheck[attribute + "EQ"]);
						est->attributeCount += 1;
						est->estimatedtuples = est->attributeCount * local_estimate;
					}

					if(curParse != "OR")
					{
						long double tempResult = 1.0;
						map<string, EstimateMetaInfo>::iterator it;
						for(it = EstCheck.begin(); it !=EstCheck.end(); it++)
						{
							if(it->second.attributeCount == 1)
								tempResult *= it->second.estimatedtuples;
							else
								tempResult *= (1 - it->second.estimatedtuples);
						}

						long double totalCurrentEstimate = 1.0 - tempResult;
						estimates.push_back(totalCurrentEstimate);
						EstCheck.clear();
					}
				}

				else
				{
					local_estimate = 1.0/tableinfo.AttributeMap[attribute];
					estimates.push_back(local_estimate);
				}
			}
			else
			{
				if((curParse == "OR") || (prev_parse == "OR"))
				{
					local_estimate = (1.0 - 1.0/3);

					EstimateMetaInfo *est = new EstimateMetaInfo();
					est->attributeCount = 1;
					est->estimatedtuples = local_estimate;
					EstCheck[attribute] = *est;
					if(curParse != "OR")
					{
						long double tempResult = 1.0;
						long double totalCurrentEstimate;
						map<string, EstimateMetaInfo>::iterator it ;
						for(it = EstCheck.begin(); it != EstCheck.end(); it++)
						{
							if(it->second.attributeCount == 1)
								tempResult *= it->second.estimatedtuples;	
							else
								tempResult *= (1 - it->second.estimatedtuples);
						}

						totalCurrentEstimate = 1.0 - tempResult;
						estimates.push_back(totalCurrentEstimate);
						EstCheck.clear();
					}
				}
				else
				{
					local_estimate = (1.0/3);
					estimates.push_back(local_estimate);
				}

			}
		}
		prev_parse = curParse;
	}

	double result = getRes( jointableset,estimates);
	return result;
}

double Statistics:: getRes(set <string> &jointableset,vector<double> &estimates)
{
	unsigned long long int estNum = 1;    

		set <string>::iterator it ;
		for (it = jointableset.begin(); it != jointableset.end(); it++)
		{
			string id = *it;
			if(statMap[id].partition_number==1)
			{
				int newid = RelationJoinMap[id];
				stringstream convert;   
				convert << newid;      
				id = convert.str();
			}

			estNum *= statMap[id].numtuples;
		}
		double result = estNum;
		for(int i = 0; i < estimates.size(); i++)   
		{
			result *= estimates[i];
		}
		return result;
}
