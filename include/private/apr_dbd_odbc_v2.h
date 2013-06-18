begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  ONLY USED FOR ODBC Version 2   -DODBCV2 * *   Re-define everything to work (more-or-less) in an ODBC V2 environment *       Random access to retrieved rows is not supported - i.e. calls to apr_dbd_select() cannot *       have a 'random' argument of 1.  apr_dbd_get_row() must always pass rownum as 0 (get next row) * */
end_comment

begin_define
define|#
directive|define
name|SQLHANDLE
value|SQLHENV
end_define

begin_comment
comment|/* Presumes that ENV, DBC, and STMT handles are all the same datatype */
end_comment

begin_define
define|#
directive|define
name|SQL_NULL_HANDLE
value|0
end_define

begin_define
define|#
directive|define
name|SQL_HANDLE_STMT
value|1
end_define

begin_define
define|#
directive|define
name|SQL_HANDLE_DBC
value|2
end_define

begin_define
define|#
directive|define
name|SQL_HANDLE_ENV
value|3
end_define

begin_define
define|#
directive|define
name|SQL_NO_DATA
value|SQL_NO_DATA_FOUND
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SQL_SUCCEEDED
end_ifndef

begin_define
define|#
directive|define
name|SQL_SUCCEEDED
parameter_list|(
name|rc
parameter_list|)
value|(((rc)&(~1))==0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|SQLSetEnvAttr
end_undef

begin_define
define|#
directive|define
name|SQLSetEnvAttr
parameter_list|(
name|henv
parameter_list|,
name|Attribute
parameter_list|,
name|Value
parameter_list|,
name|StringLength
parameter_list|)
value|(0)
end_define

begin_undef
undef|#
directive|undef
name|SQLAllocHandle
end_undef

begin_define
define|#
directive|define
name|SQLAllocHandle
parameter_list|(
name|type
parameter_list|,
name|parent
parameter_list|,
name|hndl
parameter_list|)
define|\
value|(     (type == SQL_HANDLE_STMT) ? SQLAllocStmt(parent, hndl) \     : (type == SQL_HANDLE_ENV)  ? SQLAllocEnv(hndl) \     :                             SQLAllocConnect(parent, hndl)  \ )
end_define

begin_undef
undef|#
directive|undef
name|SQLFreeHandle
end_undef

begin_define
define|#
directive|define
name|SQLFreeHandle
parameter_list|(
name|type
parameter_list|,
name|hndl
parameter_list|)
define|\
value|(     (type == SQL_HANDLE_STMT) ? SQLFreeStmt(hndl, SQL_DROP) \     : (type == SQL_HANDLE_ENV)  ? SQLFreeEnv(hndl) \     :                             SQLFreeConnect(hndl)  \ )
end_define

begin_undef
undef|#
directive|undef
name|SQLGetDiagRec
end_undef

begin_define
define|#
directive|define
name|SQLGetDiagRec
parameter_list|(
name|type
parameter_list|,
name|h
parameter_list|,
name|i
parameter_list|,
name|state
parameter_list|,
name|native
parameter_list|,
name|buffer
parameter_list|,
name|bufsize
parameter_list|,
name|reslen
parameter_list|)
define|\
value|SQLError(  (type == SQL_HANDLE_ENV) ? h : NULL, \                    (type == SQL_HANDLE_DBC) ? h : NULL, \                    (type == SQL_HANDLE_STMT) ? h : NULL, \                    state, native, buffer, bufsize, reslen)
end_define

begin_undef
undef|#
directive|undef
name|SQLCloseCursor
end_undef

begin_define
define|#
directive|define
name|SQLCloseCursor
parameter_list|(
name|stmt
parameter_list|)
value|SQLFreeStmt(stmt, SQL_CLOSE)
end_define

begin_undef
undef|#
directive|undef
name|SQLGetConnectAttr
end_undef

begin_define
define|#
directive|define
name|SQLGetConnectAttr
parameter_list|(
name|hdbc
parameter_list|,
name|fOption
parameter_list|,
name|ValuePtr
parameter_list|,
name|BufferLength
parameter_list|,
name|NULL
parameter_list|)
define|\
value|SQLGetConnectOption(hdbc, fOption, ValuePtr)
end_define

begin_undef
undef|#
directive|undef
name|SQLSetConnectAttr
end_undef

begin_define
define|#
directive|define
name|SQLSetConnectAttr
parameter_list|(
name|hdbc
parameter_list|,
name|fOption
parameter_list|,
name|ValuePtr
parameter_list|,
name|BufferLength
parameter_list|)
define|\
value|SQLSetConnectOption(hdbc, fOption, (SQLUINTEGER) ValuePtr)
end_define

begin_undef
undef|#
directive|undef
name|SQLSetStmtAttr
end_undef

begin_define
define|#
directive|define
name|SQLSetStmtAttr
parameter_list|(
name|hstmt
parameter_list|,
name|fOption
parameter_list|,
name|ValuePtr
parameter_list|,
name|BufferLength
parameter_list|)
value|(0); return APR_ENOTIMPL;
end_define

begin_undef
undef|#
directive|undef
name|SQLEndTran
end_undef

begin_define
define|#
directive|define
name|SQLEndTran
parameter_list|(
name|hType
parameter_list|,
name|hdbc
parameter_list|,
name|type
parameter_list|)
value|SQLTransact(henv, hdbc, type)
end_define

begin_undef
undef|#
directive|undef
name|SQLFetchScroll
end_undef

begin_define
define|#
directive|define
name|SQLFetchScroll
parameter_list|(
name|stmt
parameter_list|,
name|orient
parameter_list|,
name|rownum
parameter_list|)
value|(0); return APR_ENOTIMPL;
end_define

begin_define
define|#
directive|define
name|SQL_DESC_TYPE
value|SQL_COLUMN_TYPE
end_define

begin_define
define|#
directive|define
name|SQL_DESC_CONCISE_TYPE
value|SQL_COLUMN_TYPE
end_define

begin_define
define|#
directive|define
name|SQL_DESC_DISPLAY_SIZE
value|SQL_COLUMN_DISPLAY_SIZE
end_define

begin_define
define|#
directive|define
name|SQL_DESC_OCTET_LENGTH
value|SQL_COLUMN_LENGTH
end_define

begin_define
define|#
directive|define
name|SQL_DESC_UNSIGNED
value|SQL_COLUMN_UNSIGNED
end_define

begin_undef
undef|#
directive|undef
name|SQLColAttribute
end_undef

begin_define
define|#
directive|define
name|SQLColAttribute
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|,
name|m
parameter_list|,
name|n
parameter_list|)
value|SQLColAttributes(s, c, f, a, l, m, n)
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_ACCESS_MODE
value|SQL_ACCESS_MODE
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_AUTOCOMMIT
value|SQL_AUTOCOMMIT
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_CONNECTION_TIMEOUT
value|113
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_CURRENT_CATALOG
value|SQL_CURRENT_QUALIFIER
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_DISCONNECT_BEHAVIOR
value|114
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_ENLIST_IN_DTC
value|1207
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_ENLIST_IN_XA
value|1208
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_CONNECTION_DEAD
value|1209
end_define

begin_define
define|#
directive|define
name|SQL_CD_TRUE
value|1L
end_define

begin_comment
comment|/* Connection is closed/dead */
end_comment

begin_define
define|#
directive|define
name|SQL_CD_FALSE
value|0L
end_define

begin_comment
comment|/* Connection is open/available */
end_comment

begin_define
define|#
directive|define
name|SQL_ATTR_LOGIN_TIMEOUT
value|SQL_LOGIN_TIMEOUT
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_ODBC_CURSORS
value|SQL_ODBC_CURSORS
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_PACKET_SIZE
value|SQL_PACKET_SIZE
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_QUIET_MODE
value|SQL_QUIET_MODE
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_TRACE
value|SQL_OPT_TRACE
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_TRACEFILE
value|SQL_OPT_TRACEFILE
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_TRANSLATE_LIB
value|SQL_TRANSLATE_DLL
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_TRANSLATE_OPTION
value|SQL_TRANSLATE_OPTION
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_TXN_ISOLATION
value|SQL_TXN_ISOLATION
end_define

begin_define
define|#
directive|define
name|SQL_ATTR_CURSOR_SCROLLABLE
value|-1
end_define

begin_define
define|#
directive|define
name|SQL_C_SBIGINT
value|(SQL_BIGINT+SQL_SIGNED_OFFSET)
end_define

begin_comment
comment|/* SIGNED BIGINT */
end_comment

begin_define
define|#
directive|define
name|SQL_C_UBIGINT
value|(SQL_BIGINT+SQL_UNSIGNED_OFFSET)
end_define

begin_comment
comment|/* UNSIGNED BIGINT */
end_comment

begin_define
define|#
directive|define
name|SQL_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|SQL_TRUE
value|1
end_define

end_unit

