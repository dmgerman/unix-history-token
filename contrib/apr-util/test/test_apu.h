begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/* Some simple functions to make the test apps easier to write and  * a bit more consistent...  * this is a>copy< of apr_test.h  */
end_comment

begin_comment
comment|/* Things to bear in mind when using these...  *  * If you include '\t' within the string passed in it won't be included  * in the spacing, so use spaces instead :)  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APU_TEST_INCLUDES
end_ifndef

begin_define
define|#
directive|define
name|APU_TEST_INCLUDES
end_define

begin_include
include|#
directive|include
file|"apr_strings.h"
end_include

begin_include
include|#
directive|include
file|"apr_time.h"
end_include

begin_define
define|#
directive|define
name|TEST_EQ
parameter_list|(
name|str
parameter_list|,
name|func
parameter_list|,
name|value
parameter_list|,
name|good
parameter_list|,
name|bad
parameter_list|)
define|\
value|printf("%-60s", str); \     { \     apr_status_t rv; \     if ((rv = func) == value){ \         char errmsg[200]; \         printf("%s\n", bad); \         fprintf(stderr, "Error was %d : %s\n", rv, \                 apr_strerror(rv, (char*)&errmsg, 200)); \         exit(-1); \     } \     printf("%s\n", good); \     }
end_define

begin_define
define|#
directive|define
name|TEST_NEQ
parameter_list|(
name|str
parameter_list|,
name|func
parameter_list|,
name|value
parameter_list|,
name|good
parameter_list|,
name|bad
parameter_list|)
define|\
value|printf("%-60s", str); \     { \     apr_status_t rv; \     if ((rv = func) != value){ \         char errmsg[200]; \         printf("%s\n", bad); \         fprintf(stderr, "Error was %d : %s\n", rv, \                 apr_strerror(rv, (char*)&errmsg, 200)); \         exit(-1); \     } \     printf("%s\n", good); \     }
end_define

begin_define
define|#
directive|define
name|TEST_STATUS
parameter_list|(
name|str
parameter_list|,
name|func
parameter_list|,
name|testmacro
parameter_list|,
name|good
parameter_list|,
name|bad
parameter_list|)
define|\
value|printf("%-60s", str); \     { \         apr_status_t rv = func; \         if (!testmacro(rv)) { \             char errmsg[200]; \             printf("%s\n", bad); \             fprintf(stderr, "Error was %d : %s\n", rv, \                     apr_strerror(rv, (char*)&errmsg, 200)); \             exit(-1); \         } \         printf("%s\n", good); \     }
end_define

begin_define
define|#
directive|define
name|STD_TEST_NEQ
parameter_list|(
name|str
parameter_list|,
name|func
parameter_list|)
define|\
value|TEST_NEQ(str, func, APR_SUCCESS, "OK", "Failed");
end_define

begin_define
define|#
directive|define
name|PRINT_ERROR
parameter_list|(
name|rv
parameter_list|)
define|\
value|{ \         char errmsg[200]; \         fprintf(stderr, "Error was %d : %s\n", rv, \                 apr_strerror(rv, (char*)&errmsg, 200)); \         exit(-1); \     }
end_define

begin_define
define|#
directive|define
name|MSG_AND_EXIT
parameter_list|(
name|msg
parameter_list|)
define|\
value|printf("%s\n", msg); \     exit (-1);
end_define

begin_define
define|#
directive|define
name|TIME_FUNCTION
parameter_list|(
name|time
parameter_list|,
name|function
parameter_list|)
define|\
value|{ \         apr_time_t tt = apr_time_now(); \         function; \         time = apr_time_now() - tt; \     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APU_TEST_INCLUDES */
end_comment

end_unit

