#include <sys/types.h>
#include <string.h>
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
	DBT key, data;
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

	memset(&key,  0, sizeof(key));
	memset(&data, 0, sizeof(data));

	key.data  = (void *)"fruit";
	key.size  = sizeof("fruit");

	data.data = (void *)"apple";
	data.size = sizeof("apple");

	ret = dbp->put(dbp, NULL, &key, &data, 0);
	if (!ret)
	{
		printf("db: %s: key stored.\n", (char *)key.data);
	}
	else
	{
		dbp->err(dbp, ret, "DB->put");
		exit(1);
	}

	return 0;
}

