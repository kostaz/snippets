#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <db.h>

#define DATABASE "access.db"

/*******************************************************************************
 * main
 */
int main()
{
	DB* dbp;
	int ret;

	ret = db_create(&dbp, NULL, 0);
	if (ret)
	{
		fprintf(stderr, "%s: Error: db_create failed: %s\n",
			__func__, db_strerror(ret));
		exit(1);
	}

	ret = dbp->open(dbp, NULL, DATABASE, NULL, DB_BTREE, DB_CREATE, 0664);
	if (ret)
	{
		dbp->err(dbp, ret, "%s", DATABASE);
		exit(1);
	}


	return 0;
}

