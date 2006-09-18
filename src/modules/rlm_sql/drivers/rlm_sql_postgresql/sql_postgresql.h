
#ifndef _SQL_POSTGRESQL_H_
#define _SQL_POSTGRESQL_H_

/************************************************** 
* Error Codes and required information Lookup table
* Does this shite ever needed? Lets c.. 
***************************************************/
typedef struct pgsql_error{
	char *errorcode;
	char *meaning;
	int  shouldreconnect;
}pgerror;

pgerror errorcodes[]=
{
	"1000", "WARNING", 0,
	"0100C", "DYNAMIC RESULT SETS RETURNED", 0,
	"1008", "IMPLICIT ZERO BIT PADDING", 0,
	"1003", "NULL VALUE ELIMINATED IN SET FUNCTION", 0,
	"1007", "PRIVILEGE NOT GRANTED", 0,
	"1006", "PRIVILEGE NOT REVOKED", 0,
	"1004", "STRING DATA RIGHT TRUNCATION", 0,
	"01P01", "DEPRECATED FEATURE", 0,

	"2000", "NO DATA", 0,
	"2001", "NO ADDITIONAL DYNAMIC RESULT SETS RETURNED", 0,
	
	"3000", "SQL STATEMENT NOT YET COMPLETE", 0,

	"8000", "CONNECTION EXCEPTION", 0,
	"8003", "CONNECTION DOES NOT EXIST", 0,
	"8006", "CONNECTION FAILURE", 0,
	"8001", "SQLCLIENT UNABLE TO ESTABLISH SQLCONNECTION", 0,
	"8004", "SQLSERVER REJECTED ESTABLISHMENT OF SQLCONNECTION", 0,
	"8007", "TRANSACTION RESOLUTION UNKNOWN", 0,
	"08P01", "PROTOCOL VIOLATION", 0,

	"9000", "TRIGGERED ACTION EXCEPTION", 0,

	"0A000", "FEATURE NOT SUPPORTED", 0,

	"0B000", "INVALID TRANSACTION INITIATION", 0,

	"0F000", "LOCATOR EXCEPTION", 0,
	"0F001", "INVALID LOCATOR SPECIFICATION", 0,

	"0L000", "INVALID GRANTOR", 0,
	"0LP01", "INVALID GRANT OPERATION", 0,

	"21000", "CARDINALITY VIOLATION", 0,

	"22000", "DATA EXCEPTION", 0,
	"2202E", "ARRAY SUBSCRIPT ERROR", 0,
	"22021", "CHARACTER NOT IN REPERTOIRE", 0,
	"22008", "DATETIME FIELD OVERFLOW", 0,
	"22012", "DIVISION BY ZERO", 0,
	"22005", "ERROR IN ASSIGNMENT", 0,
	"2200B", "ESCAPE CHARACTER CONFLICT", 0,
	"22022", "INDICATOR OVERFLOW", 0,
	"22015", "INTERVAL FIELD OVERFLOW", 0,
	"2201E", "INVALID ARGUMENT FOR LOGARITHM", 0,
	"2201F", "INVALID ARGUMENT FOR POWER FUNCTION", 0,
	"2201G", "INVALID ARGUMENT FOR WIDTH BUCKET FUNCTION", 0,
	"22018", "INVALID CHARACTER VALUE FOR CAST", 0,
	"22007", "INVALID DATETIME FORMAT", 0,
	"22019", "INVALID ESCAPE CHARACTER", 0,
	"2200D", "INVALID ESCAPE OCTET", 0,
	"22025", "INVALID ESCAPE SEQUENCE", 0,
	"22P06", "NONSTANDARD USE OF ESCAPE CHARACTER", 0,
	"22010", "INVALID INDICATOR PARAMETER VALUE", 0,
	"22020", "INVALID LIMIT VALUE", 0,
	"22023", "INVALID PARAMETER VALUE", 0,
	"2201B", "INVALID REGULAR EXPRESSION", 0,
	"22009", "INVALID TIME ZONE DISPLACEMENT VALUE", 0,
	"2200C", "INVALID USE OF ESCAPE CHARACTER", 0,
	"2200G", "MOST SPECIFIC TYPE MISMATCH", 0,
	"22004", "NULL VALUE NOT ALLOWED", 0,
	"22002", "NULL VALUE NO INDICATOR PARAMETER", 0,
	"22003", "NUMERIC VALUE OUT OF RANGE", 0,
	"22026", "STRING DATA LENGTH MISMATCH", 0,
	"22001", "STRING DATA RIGHT TRUNCATION", 0,
	"22011", "SUBSTRING ERROR", 0,
	"22027", "TRIM ERROR", 0,
	"22024", "UNTERMINATED C STRING", 0,
	"2200F", "ZERO LENGTH CHARACTER STRING", 0,
	"22P01", "FLOATING POINT EXCEPTION", 0,
	"22P02", "INVALID TEXT REPRESENTATION", 0,
	"22P03", "INVALID BINARY REPRESENTATION", 0,
	"22P04", "BAD COPY FILE FORMAT", 0,
	"22P05", "UNTRANSLATABLE CHARACTER", 0,

	"23000", "INTEGRITY CONSTRAINT VIOLATION", 0,
	"23001", "RESTRICT VIOLATION", 0,
	"23502", "NOT NULL VIOLATION", 0,
	"23503", "FOREIGN KEY VIOLATION", 0,
	"23505", "UNIQUE VIOLATION", 0,
	"23514", "CHECK VIOLATION", 0,

	"24000", "INVALID CURSOR STATE", 0,

	"25000", "INVALID TRANSACTION STATE", 0,
	"25001", "ACTIVE SQL TRANSACTION", 0,
	"25002", "BRANCH TRANSACTION ALREADY ACTIVE", 0,
	"25008", "HELD CURSOR REQUIRES SAME ISOLATION LEVEL", 0,
	"25003", "INAPPROPRIATE ACCESS MODE FOR BRANCH TRANSACTION", 0,
	"25004", "INAPPROPRIATE ISOLATION LEVEL FOR BRANCH TRANSACTION", 0,
	"25005", "NO ACTIVE SQL TRANSACTION FOR BRANCH TRANSACTION", 0,
	"25006", "READ ONLY SQL TRANSACTION", 0,
	"25007", "SCHEMA AND DATA STATEMENT MIXING NOT SUPPORTED", 0,
	"25P01", "NO ACTIVE SQL TRANSACTION", 0,
	"25P02", "IN FAILED SQL TRANSACTION", 0,

	"26000", "INVALID SQL STATEMENT NAME", 0,

	"27000", "TRIGGERED DATA CHANGE VIOLATION", 0,

	"28000", "INVALID AUTHORIZATION SPECIFICATION", 0,

	"2B000", "DEPENDENT PRIVILEGE DESCRIPTORS STILL EXIST", 0,
	"2BP01", "DEPENDENT OBJECTS STILL EXIST", 0,
	
	"2D000", "INVALID TRANSACTION TERMINATION", 0,
	
	"2F000", "SQL ROUTINE EXCEPTION", 0,
	"2F005", "FUNCTION EXECUTED NO RETURN STATEMENT", 0,
	"2F002", "MODIFYING SQL DATA NOT PERMITTED", 0,
	"2F003", "PROHIBITED SQL STATEMENT ATTEMPTED", 0,
	"2F004", "READING SQL DATA NOT PERMITTED", 0,

	"34000", "INVALID CURSOR NAME", 0,
	
	"38000", "EXTERNAL ROUTINE EXCEPTION", 0,
	"38001", "CONTAINING SQL NOT PERMITTED", 0,
	"38002", "MODIFYING SQL DATA NOT PERMITTED", 0,
	"38003", "PROHIBITED SQL STATEMENT ATTEMPTED", 0,
	"38004", "READING SQL DATA NOT PERMITTED", 0,

	"39000", "EXTERNAL ROUTINE INVOCATION EXCEPTION", 0,
	"39001", "INVALID SQLSTATE RETURNED", 0,
	"39004", "NULL VALUE NOT ALLOWED", 0,
	"39P01", "TRIGGER PROTOCOL VIOLATED", 0,
	"39P02", "SRF PROTOCOL VIOLATED", 0,

	"3B000", "SAVEPOINT EXCEPTION", 0,
	"3B001", "INVALID SAVEPOINT SPECIFICATION", 0,

	"3D000", "INVALID CATALOG NAME", 0,
	"3F000", "INVALID SCHEMA NAME", 0,

	"40000", "TRANSACTION ROLLBACK", 0,
	"40002", "TRANSACTION INTEGRITY CONSTRAINT VIOLATION", 0,
	"40001", "SERIALIZATION FAILURE", 0,
	"40003", "STATEMENT COMPLETION UNKNOWN", 0,
	"40P01", "DEADLOCK DETECTED", 0,

	"44000", "WITH CHECK OPTION VIOLATION", 0,

	"53000", "INSUFFICIENT RESOURCES", 0,
	"53100", "DISK FULL", 0,
	"53200", "OUT OF MEMORY", 0,
	"53300", "TOO MANY CONNECTIONS", 0,
	
	"54000", "PROGRAM LIMIT EXCEEDED", 0,
	"54001", "STATEMENT TOO COMPLEX", 0,
	"54011", "TOO MANY COLUMNS", 0,
	"54023", "TOO MANY ARGUMENTS", 0,

	"55000", "OBJECT NOT IN PREREQUISITE STATE", 0,
	"55006", "OBJECT IN USE", 0,
	"55P02", "CANT CHANGE RUNTIME PARAM", 0,	
	"55P03", "LOCK NOT AVAILABLE", 0,
	
	"57000", "OPERATOR INTERVENTION", 1,
	"57014", "QUERY CANCELED", 1,
	"57P01", "ADMIN SHUTDOWN", 1,
	"57P02", "CRASH SHUTDOWN", 1,
	"57P03", "CANNOT CONNECT NOW", 1,

	"58030", "IO ERROR", 1,
	"58P01", "UNDEFINED FILE", 1,
	"58P02", "DUPLICATE FILE", 1,

	"F0000", "CONFIG FILE ERROR", 1,
	"F0001", "LOCK FILE EXISTS", 1,

	"P0000", "PLPGSQL ERROR", 0,
	"P0001", "RAISE EXCEPTION", 0,

	"42000", "SYNTAX ERROR OR ACCESS RULE VIOLATION", 0,
	"42601", "SYNTAX ERROR", 0,
	"42501", "INSUFFICIENT PRIVILEGE", 0,
	"42846", "CANNOT COERCE", 0,
	"42803", "GROUPING ERROR", 0,
	"42830", "INVALID FOREIGN KEY", 0,
	"42602", "INVALID NAME", 0,
	"42622", "NAME TOO LONG", 0,
	"42939", "RESERVED NAME", 0,
	"42804", "DATATYPE MISMATCH", 0,
	"42P18", "INDETERMINATE DATATYPE", 0,
	"42809", "WRONG OBJECT TYPE", 0,
	"42703", "UNDEFINED COLUMN", 0,
	"42883", "UNDEFINED FUNCTION", 0,
	"42P01", "UNDEFINED TABLE", 0,
	"42P02", "UNDEFINED PARAMETER", 0,
	"42704", "UNDEFINED OBJECT", 0,
	"42701", "DUPLICATE COLUMN", 0,	
	"42P03", "DUPLICATE CURSOR", 0,
	"42P04", "DUPLICATE DATABASE", 0,
	"42723", "DUPLICATE FUNCTION", 0,
	"42P05", "DUPLICATE PREPARED STATEMENT", 0,
	"42P06", "DUPLICATE SCHEMA", 0,
	"42P07", "DUPLICATE TABLE", 0,
	"42712", "DUPLICATE ALIAS", 0,
	"42710", "DUPLICATE OBJECT", 0,
	"42702", "AMBIGUOUS COLUMN", 0,
	"42725", "AMBIGUOUS FUNCTION", 0,
	"42P08", "AMBIGUOUS PARAMETER", 0,
	"42P09", "AMBIGUOUS ALIAS", 0,
	"42P10", "INVALID COLUMN REFERENCE", 0,
	"42611", "INVALID COLUMN DEFINITION", 0,
	"42P11", "INVALID CURSOR DEFINITION", 0,
	"42P12", "INVALID DATABASE DEFINITION", 0,
	"42P13", "INVALID FUNCTION DEFINITION", 0,
	"42P14", "INVALID PREPARED STATEMENT DEFINITION", 0,
	"42P15", "INVALID SCHEMA DEFINITION", 0,
	"42P16", "INVALID TABLE DEFINITION", 0,
	"42P17", "INVALID OBJECT DEFINITION", 0,

	"XX000", "INTERNAL ERROR", 0,
	"XX001", "DATA CORRUPTED", 0,
	"XX002", "INDEX CORRUPTED", 0,

	NULL, NULL, 0
};

#endif /*_SQL_POSTGRESQL_H_*/
