begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bdb_compat.c --- Compatibility wrapper for different BDB versions.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|"bdb_compat.h"
end_include

begin_function
name|int
name|svn_fs_bdb__check_version
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|major
decl_stmt|,
name|minor
decl_stmt|;
name|db_version
argument_list|(
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|major
operator|!=
name|DB_VERSION_MAJOR
operator|||
name|minor
operator|!=
name|DB_VERSION_MINOR
condition|)
return|return
name|DB_OLD_VERSION
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

