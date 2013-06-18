begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDDEF_H
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* for NULL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_strings.h"
end_include

begin_define
define|#
directive|define
name|APR_WANT_STRFUNC
end_define

begin_comment
comment|/* for strchr() */
end_comment

begin_include
include|#
directive|include
file|"apr_want.h"
end_include

begin_macro
name|APR_DECLARE
argument_list|(
argument|char *
argument_list|)
end_macro

begin_macro
name|apr_strtok
argument_list|(
argument|char *str
argument_list|,
argument|const char *sep
argument_list|,
argument|char **last
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|token
decl_stmt|;
if|if
condition|(
operator|!
name|str
condition|)
comment|/* subsequent call */
name|str
operator|=
operator|*
name|last
expr_stmt|;
comment|/* start where we left off */
comment|/* skip characters in sep (will terminate at '\0') */
while|while
condition|(
operator|*
name|str
operator|&&
name|strchr
argument_list|(
name|sep
argument_list|,
operator|*
name|str
argument_list|)
condition|)
operator|++
name|str
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|str
condition|)
comment|/* no more tokens */
return|return
name|NULL
return|;
name|token
operator|=
name|str
expr_stmt|;
comment|/* skip valid token characters to terminate token and      * prepare for the next call (will terminate at '\0)       */
operator|*
name|last
operator|=
name|token
operator|+
literal|1
expr_stmt|;
while|while
condition|(
operator|*
operator|*
name|last
operator|&&
operator|!
name|strchr
argument_list|(
name|sep
argument_list|,
operator|*
operator|*
name|last
argument_list|)
condition|)
operator|++
operator|*
name|last
expr_stmt|;
if|if
condition|(
operator|*
operator|*
name|last
condition|)
block|{
operator|*
operator|*
name|last
operator|=
literal|'\0'
expr_stmt|;
operator|++
operator|*
name|last
expr_stmt|;
block|}
return|return
name|token
return|;
block|}
end_block

end_unit

