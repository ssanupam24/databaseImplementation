#include "TwoWayList.h"
#include "Record.h"
#include "Schema.h"
#include "File.h"
#include "Comparison.h"
#include "ComparisonEngine.h"
#include "DBFile.h"
#include "Defs.h"
#include "string.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
/**
 * @method getMetaDataFileName to generate file name for metadata based on file input. Meta data will be created with name as
 * filename.meta.
 * @param f_path character pointer to file path including file name.
 */
char * DBFile:: getMetaDataFileName(char* f_path)
{
	char* metaFileName = (char*) malloc((strlen(f_path) + strlen(".meta") + 1)*sizeof(char));
	//create meta file name as fpath + ".meta"
	strcpy(metaFileName,f_path);
	strcat(metaFileName,".meta");
	return metaFileName;
}

DBFile::DBFile () {

}
/**
 * @method Create to create a new DBFile instance based on file type specified. If file type specified is heap method initialises 
 * instance of GenericDBFile to new Heap instance and writes "heap" to meta data file. If file type specified is sorted method 
 * initialises instance of GenericDBFile to new Sorted instance and writes "sorted" to meta data file. 
 * Method also initialises Meta data file with instance of OrderMaker class object.
 */
int DBFile::Create (char *f_path, fType f_type, void *startup) 
{
	int status = 1;
    char * metafileName =  getMetaDataFileName(f_path);
    ofstream outfile(metafileName,std::ofstream::out);
    
    int fileType = f_type;
    outfile<<fileType<<endl;

	//if File type spcified is heap type initialise variable with heap and call the instance's create method.
	if(f_type == heap)
	{
		dbFile = new HeapFile();
		status = dbFile->Create(f_path,f_type,startup);	

	}else if(f_type == sorted)
	{
		dbFile = new SortedFile();
		status = dbFile->Create(f_path, f_type, startup);	
	}
	return status;
}
/**
 * @method to load all the records from a text file specified to a binary file in sorted
 * order based on sort order specified.
 *
 */
void DBFile::Load (Schema &f_schema, char *loadpath) 
{
	dbFile->Load(f_schema,loadpath);
}
/**
 * @method opens a existing bin file, reads metadata associated with file and initialises
 * genericdbfile instance based on the type of file specified in metadata.
 *
 */
int DBFile::Open (char *f_path) 
{
	char* metaFileName = getMetaDataFileName(f_path);
	
    ifstream infile(metaFileName,std::ifstream::in);
    int fileType;
    infile>>fileType;
    infile.close();
	if(heap == fileType)
    {
        dbFile = new HeapFile();
    }
	else if(sorted == fileType)
    {
        dbFile = new SortedFile();
    }
	return dbFile->Open(f_path);	
}
/**
 * @method MoveFirst to move to first record.
 */
void DBFile::MoveFirst () 
{
	dbFile->MoveFirst();
}
/**
 * @method close to close the dbfile instance which is delegated to
 * corresponding object.
 */
int DBFile::Close () 
{
	int dbfileStatus = dbFile->Close();
	return dbfileStatus;
}

void DBFile::Add (Record &rec) 
{
	dbFile->Add(rec);
}

int DBFile::GetNext (Record &fetchme) 
{
	return dbFile->GetNext(fetchme);
}

int DBFile::GetNext (Record &fetchme, CNF &cnf, Record &literal) {
    return dbFile->GetNext(fetchme,cnf,literal);
}
