begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/* Overview of what this is and does:  * http://www.apache.org/~niq/dbd.html  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_DBD_H
end_ifndef

begin_define
define|#
directive|define
name|APR_DBD_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * @file apr_dbd.h  * @brief APR-UTIL DBD library  */
comment|/**  * @defgroup APR_Util_DBD DBD routines  * @ingroup APR_Util  * @{  */
comment|/**  * Mapping of C to SQL types, used for prepared statements.  * @remarks  * For apr_dbd_p[v]query/select functions, in and out parameters are always  * const char * (i.e. regular nul terminated strings). LOB types are passed  * with four (4) arguments: payload, length, table and column, all as const  * char *, where table and column are reserved for future use by Oracle.  * @remarks  * For apr_dbd_p[v]bquery/select functions, in and out parameters are  * described next to each enumeration constant and are generally native binary  * types or some APR data type. LOB types are passed with four (4) arguments:  * payload (char*), length (apr_size_t*), table (char*) and column (char*).  * Table and column are reserved for future use by Oracle.  */
typedef|typedef
enum|enum
block|{
name|APR_DBD_TYPE_NONE
block|,
name|APR_DBD_TYPE_TINY
block|,
comment|/**< \%hhd : in, out: char* */
name|APR_DBD_TYPE_UTINY
block|,
comment|/**< \%hhu : in, out: unsigned char* */
name|APR_DBD_TYPE_SHORT
block|,
comment|/**< \%hd  : in, out: short* */
name|APR_DBD_TYPE_USHORT
block|,
comment|/**< \%hu  : in, out: unsigned short* */
name|APR_DBD_TYPE_INT
block|,
comment|/**< \%d   : in, out: int* */
name|APR_DBD_TYPE_UINT
block|,
comment|/**< \%u   : in, out: unsigned int* */
name|APR_DBD_TYPE_LONG
block|,
comment|/**< \%ld  : in, out: long* */
name|APR_DBD_TYPE_ULONG
block|,
comment|/**< \%lu  : in, out: unsigned long* */
name|APR_DBD_TYPE_LONGLONG
block|,
comment|/**< \%lld : in, out: apr_int64_t* */
name|APR_DBD_TYPE_ULONGLONG
block|,
comment|/**< \%llu : in, out: apr_uint64_t* */
name|APR_DBD_TYPE_FLOAT
block|,
comment|/**< \%f   : in, out: float* */
name|APR_DBD_TYPE_DOUBLE
block|,
comment|/**< \%lf  : in, out: double* */
name|APR_DBD_TYPE_STRING
block|,
comment|/**< \%s   : in: char*, out: char** */
name|APR_DBD_TYPE_TEXT
block|,
comment|/**< \%pDt : in: char*, out: char** */
name|APR_DBD_TYPE_TIME
block|,
comment|/**< \%pDi : in: char*, out: char** */
name|APR_DBD_TYPE_DATE
block|,
comment|/**< \%pDd : in: char*, out: char** */
name|APR_DBD_TYPE_DATETIME
block|,
comment|/**< \%pDa : in: char*, out: char** */
name|APR_DBD_TYPE_TIMESTAMP
block|,
comment|/**< \%pDs : in: char*, out: char** */
name|APR_DBD_TYPE_ZTIMESTAMP
block|,
comment|/**< \%pDz : in: char*, out: char** */
name|APR_DBD_TYPE_BLOB
block|,
comment|/**< \%pDb : in: char* apr_size_t* char* char*, out: apr_bucket_brigade* */
name|APR_DBD_TYPE_CLOB
block|,
comment|/**< \%pDc : in: char* apr_size_t* char* char*, out: apr_bucket_brigade* */
name|APR_DBD_TYPE_NULL
comment|/**< \%pDn : in: void*, out: void** */
block|}
name|apr_dbd_type_e
typedef|;
comment|/* These are opaque structs.  Instantiation is up to each backend */
typedef|typedef
name|struct
name|apr_dbd_driver_t
name|apr_dbd_driver_t
typedef|;
typedef|typedef
name|struct
name|apr_dbd_t
name|apr_dbd_t
typedef|;
typedef|typedef
name|struct
name|apr_dbd_transaction_t
name|apr_dbd_transaction_t
typedef|;
typedef|typedef
name|struct
name|apr_dbd_results_t
name|apr_dbd_results_t
typedef|;
typedef|typedef
name|struct
name|apr_dbd_row_t
name|apr_dbd_row_t
typedef|;
typedef|typedef
name|struct
name|apr_dbd_prepared_t
name|apr_dbd_prepared_t
typedef|;
comment|/** apr_dbd_init: perform once-only initialisation.  Call once only.  *  *  @param pool - pool to register any shutdown cleanups, etc  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbd_init
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/** apr_dbd_get_driver: get the driver struct for a name  *  *  @param pool - (process) pool to register cleanup  *  @param name - driver name  *  @param driver - pointer to driver struct.  *  @return APR_SUCCESS for success  *  @return APR_ENOTIMPL for no driver (when DSO not enabled)  *  @return APR_EDSOOPEN if DSO driver file can't be opened  *  @return APR_ESYMNOTFOUND if the driver file doesn't contain a driver  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbd_get_driver
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|apr_dbd_driver_t
operator|*
operator|*
name|driver
argument_list|)
expr_stmt|;
comment|/** apr_dbd_open_ex: open a connection to a backend  *  *  @param driver - driver struct.  *  @param pool - working pool  *  @param params - arguments to driver (implementation-dependent)  *  @param handle - pointer to handle to return  *  @param error - descriptive error.  *  @return APR_SUCCESS for success  *  @return APR_EGENERAL if driver exists but connection failed  *  @remarks PostgreSQL: the params is passed directly to the PQconnectdb()  *  function (check PostgreSQL documentation for more details on the syntax).  *  @remarks SQLite2: the params is split on a colon, with the first part used  *  as the filename and second part converted to an integer and used as file  *  mode.  *  @remarks SQLite3: the params is passed directly to the sqlite3_open()  *  function as a filename to be opened (check SQLite3 documentation for more  *  details).  *  @remarks Oracle: the params can have "user", "pass", "dbname" and "server"  *  keys, each followed by an equal sign and a value. Such key/value pairs can  *  be delimited by space, CR, LF, tab, semicolon, vertical bar or comma.  *  @remarks MySQL: the params can have "host", "port", "user", "pass",  *  "dbname", "sock", "flags" "fldsz", "group" and "reconnect" keys, each  *  followed by an equal sign and a value. Such key/value pairs can be  *  delimited by space, CR, LF, tab, semicolon, vertical bar or comma. For  *  now, "flags" can only recognise CLIENT_FOUND_ROWS (check MySQL manual for  *  details). The value associated with "fldsz" determines maximum amount of  *  memory (in bytes) for each of the fields in the result set of prepared  *  statements. By default, this value is 1 MB. The value associated with  *  "group" determines which group from configuration file to use (see  *  MYSQL_READ_DEFAULT_GROUP option of mysql_options() in MySQL manual).  *  Reconnect is set to 1 by default (i.e. true).  *  @remarks FreeTDS: the params can have "username", "password", "appname",  *  "dbname", "host", "charset", "lang" and "server" keys, each followed by an  *  equal sign and a value.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbd_open_ex
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
name|params
argument_list|,
name|apr_dbd_t
operator|*
operator|*
name|handle
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|error
argument_list|)
expr_stmt|;
comment|/** apr_dbd_open: open a connection to a backend  *  *  @param driver - driver struct.  *  @param pool - working pool  *  @param params - arguments to driver (implementation-dependent)  *  @param handle - pointer to handle to return  *  @return APR_SUCCESS for success  *  @return APR_EGENERAL if driver exists but connection failed  *  @see apr_dbd_open_ex  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbd_open
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
name|params
argument_list|,
name|apr_dbd_t
operator|*
operator|*
name|handle
argument_list|)
expr_stmt|;
comment|/** apr_dbd_close: close a connection to a backend  *  *  @param driver - driver struct.  *  @param handle - handle to close  *  @return APR_SUCCESS for success or error status  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbd_close
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|)
expr_stmt|;
comment|/* apr-function-shaped versions of things */
comment|/** apr_dbd_name: get the name of the driver  *  *  @param driver - the driver  *  @return - name  */
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
name|apr_dbd_name
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|)
expr_stmt|;
comment|/** apr_dbd_native_handle: get native database handle of the underlying db  *  *  @param driver - the driver  *  @param handle - apr_dbd handle  *  @return - native handle  */
name|APU_DECLARE
argument_list|(
argument|void*
argument_list|)
name|apr_dbd_native_handle
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|)
expr_stmt|;
comment|/** check_conn: check status of a database connection  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection to check  *  @return APR_SUCCESS or error  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_check_conn
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|)
expr_stmt|;
comment|/** apr_dbd_set_dbname: select database name.  May be a no-op if not supported.  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param name - the database to select  *  @return 0 for success or error code  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_set_dbname
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
comment|/** apr_dbd_transaction_start: start a transaction.  May be a no-op.  *  *  @param driver - the driver  *  @param pool - a pool to use for error messages (if any).  *  @param handle - the db connection  *  @param trans - ptr to a transaction.  May be null on entry  *  @return 0 for success or error code  *  @remarks Note that transaction modes, set by calling  *  apr_dbd_transaction_mode_set(), will affect all query/select calls within  *  a transaction. By default, any error in query/select during a transaction  *  will cause the transaction to inherit the error code and any further  *  query/select calls will fail immediately. Put transaction in "ignore  *  errors" mode to avoid that. Use "rollback" mode to do explicit rollback.  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_transaction_start
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|,
name|apr_dbd_transaction_t
operator|*
operator|*
name|trans
argument_list|)
expr_stmt|;
comment|/** apr_dbd_transaction_end: end a transaction  *  (commit on success, rollback on error).  *  May be a no-op.  *  *  @param driver - the driver  *  @param handle - the db connection  *  @param trans - the transaction.  *  @return 0 for success or error code  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_transaction_end
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_dbd_transaction_t
operator|*
name|trans
argument_list|)
expr_stmt|;
define|#
directive|define
name|APR_DBD_TRANSACTION_COMMIT
value|0x00
comment|/**< commit the transaction */
define|#
directive|define
name|APR_DBD_TRANSACTION_ROLLBACK
value|0x01
comment|/**< rollback the transaction */
define|#
directive|define
name|APR_DBD_TRANSACTION_IGNORE_ERRORS
value|0x02
comment|/**< ignore transaction errors */
comment|/** apr_dbd_transaction_mode_get: get the mode of transaction  *  *  @param driver - the driver  *  @param trans  - the transaction  *  @return mode of transaction  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_transaction_mode_get
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_dbd_transaction_t
operator|*
name|trans
argument_list|)
expr_stmt|;
comment|/** apr_dbd_transaction_mode_set: set the mode of transaction  *  *  @param driver - the driver  *  @param trans  - the transaction  *  @param mode   - new mode of the transaction  *  @return the mode of transaction in force after the call  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_transaction_mode_set
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_transaction_t *trans
argument_list|,
argument|int mode
argument_list|)
empty_stmt|;
comment|/** apr_dbd_query: execute an SQL query that doesn't return a result set  *  *  @param driver - the driver  *  @param handle - the connection  *  @param nrows - number of rows affected.  *  @param statement - the SQL statement to execute  *  @return 0 for success or error code  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_query
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|,
name|int
operator|*
name|nrows
argument_list|,
specifier|const
name|char
operator|*
name|statement
argument_list|)
expr_stmt|;
comment|/** apr_dbd_select: execute an SQL query that returns a result set  *  *  @param driver - the driver  *  @param pool - pool to allocate the result set  *  @param handle - the connection  *  @param res - pointer to result set pointer.  May point to NULL on entry  *  @param statement - the SQL statement to execute  *  @param random - 1 to support random access to results (seek any row);  *                  0 to support only looping through results in order  *                    (async access - faster)  *  @return 0 for success or error code  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_select
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|const char *statement
argument_list|,
argument|int random
argument_list|)
empty_stmt|;
comment|/** apr_dbd_num_cols: get the number of columns in a results set  *  *  @param driver - the driver  *  @param res - result set.  *  @return number of columns  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_num_cols
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_dbd_results_t
operator|*
name|res
argument_list|)
expr_stmt|;
comment|/** apr_dbd_num_tuples: get the number of rows in a results set  *  of a synchronous select  *  *  @param driver - the driver  *  @param res - result set.  *  @return number of rows, or -1 if the results are asynchronous  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_num_tuples
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_dbd_results_t
operator|*
name|res
argument_list|)
expr_stmt|;
comment|/** apr_dbd_get_row: get a row from a result set  *  *  @param driver - the driver  *  @param pool - pool to allocate the row  *  @param res - result set pointer  *  @param row - pointer to row pointer.  May point to NULL on entry  *  @param rownum - row number (counting from 1), or -1 for "next row".  *                  Ignored if random access is not supported.  *  @return 0 for success, -1 for rownum out of range or data finished  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_get_row
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_results_t *res
argument_list|,
argument|apr_dbd_row_t **row
argument_list|,
argument|int rownum
argument_list|)
empty_stmt|;
comment|/** apr_dbd_get_entry: get an entry from a row  *  *  @param driver - the driver  *  @param row - row pointer  *  @param col - entry number  *  @return value from the row, or NULL if col is out of bounds.  */
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
name|apr_dbd_get_entry
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_row_t *row
argument_list|,
argument|int col
argument_list|)
empty_stmt|;
comment|/** apr_dbd_get_name: get an entry name from a result set  *  *  @param driver - the driver  *  @param res - result set pointer  *  @param col - entry number  *  @return name of the entry, or NULL if col is out of bounds.  */
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
name|apr_dbd_get_name
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_results_t *res
argument_list|,
argument|int col
argument_list|)
empty_stmt|;
comment|/** apr_dbd_error: get current error message (if any)  *  *  @param driver - the driver  *  @param handle - the connection  *  @param errnum - error code from operation that returned an error  *  @return the database current error message, or message for errnum  *          (implementation-dependent whether errnum is ignored)  */
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
name|apr_dbd_error
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|int errnum
argument_list|)
empty_stmt|;
comment|/** apr_dbd_escape: escape a string so it is safe for use in query/select  *  *  @param driver - the driver  *  @param pool - pool to alloc the result from  *  @param string - the string to escape  *  @param handle - the connection  *  @return the escaped, safe string  */
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
name|apr_dbd_escape
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
name|string
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|)
expr_stmt|;
comment|/** apr_dbd_prepare: prepare a statement  *  *  @param driver - the driver  *  @param pool - pool to alloc the result from  *  @param handle - the connection  *  @param query - the SQL query  *  @param label - A label for the prepared statement.  *                 use NULL for temporary prepared statements  *                 (eg within a Request in httpd)  *  @param statement - statement to prepare.  May point to null on entry.  *  @return 0 for success or error code  *  @remarks To specify parameters of the prepared query, use \%s, \%d etc.  *  (see below for full list) in place of database specific parameter syntax  *  (e.g.  for PostgreSQL, this would be $1, $2, for SQLite3 this would be ?  *  etc.).  For instance: "SELECT name FROM customers WHERE name=%s" would be  *  a query that this function understands.  *  @remarks Here is the full list of format specifiers that this function  *  understands and what they map to in SQL: \%hhd (TINY INT), \%hhu (UNSIGNED  *  TINY INT), \%hd (SHORT), \%hu (UNSIGNED SHORT), \%d (INT), \%u (UNSIGNED  *  INT), \%ld (LONG), \%lu (UNSIGNED LONG), \%lld (LONG LONG), \%llu  *  (UNSIGNED LONG LONG), \%f (FLOAT, REAL), \%lf (DOUBLE PRECISION), \%s  *  (VARCHAR), \%pDt (TEXT), \%pDi (TIME), \%pDd (DATE), \%pDa (DATETIME),  *  \%pDs (TIMESTAMP), \%pDz (TIMESTAMP WITH TIME ZONE), \%pDb (BLOB), \%pDc  *  (CLOB) and \%pDn (NULL). Not all databases have support for all these  *  types, so the underlying driver will attempt the "best match" where  *  possible. A \% followed by any letter not in the above list will be  *  interpreted as VARCHAR (i.e. \%s).  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_prepare
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|,
specifier|const
name|char
operator|*
name|query
argument_list|,
specifier|const
name|char
operator|*
name|label
argument_list|,
name|apr_dbd_prepared_t
operator|*
operator|*
name|statement
argument_list|)
expr_stmt|;
comment|/** apr_dbd_pquery: query using a prepared statement + args  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param nrows - number of rows affected.  *  @param statement - the prepared statement to execute  *  @param nargs - ignored (for backward compatibility only)  *  @param args - args to prepared statement  *  @return 0 for success or error code  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_pquery
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|int *nrows
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int nargs
argument_list|,
argument|const char **args
argument_list|)
empty_stmt|;
comment|/** apr_dbd_pselect: select using a prepared statement + args  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param res - pointer to query results.  May point to NULL on entry  *  @param statement - the prepared statement to execute  *  @param random - Whether to support random-access to results  *  @param nargs - ignored (for backward compatibility only)  *  @param args - args to prepared statement  *  @return 0 for success or error code  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_pselect
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int random
argument_list|,
argument|int nargs
argument_list|,
argument|const char **args
argument_list|)
empty_stmt|;
comment|/** apr_dbd_pvquery: query using a prepared statement + args  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param nrows - number of rows affected.  *  @param statement - the prepared statement to execute  *  @param ... - varargs list  *  @return 0 for success or error code  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
name|apr_dbd_pvquery
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|,
name|int
operator|*
name|nrows
argument_list|,
name|apr_dbd_prepared_t
operator|*
name|statement
argument_list|,
operator|...
argument_list|)
expr_stmt|;
comment|/** apr_dbd_pvselect: select using a prepared statement + args  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param res - pointer to query results.  May point to NULL on entry  *  @param statement - the prepared statement to execute  *  @param random - Whether to support random-access to results  *  @param ... - varargs list  *  @return 0 for success or error code  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
name|apr_dbd_pvselect
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int random
argument_list|,
argument|...
argument_list|)
empty_stmt|;
comment|/** apr_dbd_pbquery: query using a prepared statement + binary args  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param nrows - number of rows affected.  *  @param statement - the prepared statement to execute  *  @param args - binary args to prepared statement  *  @return 0 for success or error code  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_pbquery
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|,
name|int
operator|*
name|nrows
argument_list|,
name|apr_dbd_prepared_t
operator|*
name|statement
argument_list|,
specifier|const
name|void
operator|*
operator|*
name|args
argument_list|)
expr_stmt|;
comment|/** apr_dbd_pbselect: select using a prepared statement + binary args  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param res - pointer to query results.  May point to NULL on entry  *  @param statement - the prepared statement to execute  *  @param random - Whether to support random-access to results  *  @param args - binary args to prepared statement  *  @return 0 for success or error code  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_dbd_pbselect
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int random
argument_list|,
argument|const void **args
argument_list|)
empty_stmt|;
comment|/** apr_dbd_pvbquery: query using a prepared statement + binary args  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param nrows - number of rows affected.  *  @param statement - the prepared statement to execute  *  @param ... - varargs list of binary args  *  @return 0 for success or error code  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
name|apr_dbd_pvbquery
argument_list|(
specifier|const
name|apr_dbd_driver_t
operator|*
name|driver
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|,
name|apr_dbd_t
operator|*
name|handle
argument_list|,
name|int
operator|*
name|nrows
argument_list|,
name|apr_dbd_prepared_t
operator|*
name|statement
argument_list|,
operator|...
argument_list|)
expr_stmt|;
comment|/** apr_dbd_pvbselect: select using a prepared statement + binary args  *  *  @param driver - the driver  *  @param pool - working pool  *  @param handle - the connection  *  @param res - pointer to query results.  May point to NULL on entry  *  @param statement - the prepared statement to execute  *  @param random - Whether to support random-access to results  *  @param ... - varargs list of binary args  *  @return 0 for success or error code  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
name|apr_dbd_pvbselect
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int random
argument_list|,
argument|...
argument_list|)
empty_stmt|;
comment|/** apr_dbd_datum_get: get a binary entry from a row  *  *  @param driver - the driver  *  @param row - row pointer  *  @param col - entry number  *  @param type - type of data to get  *  @param data - pointer to data, allocated by the caller  *  @return APR_SUCCESS on success, APR_ENOENT if data is NULL or APR_EGENERAL  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dbd_datum_get
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_row_t *row
argument_list|,
argument|int col
argument_list|,
argument|apr_dbd_type_e type
argument_list|,
argument|void *data
argument_list|)
empty_stmt|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

