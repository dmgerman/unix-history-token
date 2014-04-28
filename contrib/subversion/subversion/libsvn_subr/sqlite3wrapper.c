begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sqlite3wrapper.c  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_comment
comment|/* Include sqlite3 inline, making all symbols private. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_SQLITE_INLINE
end_ifdef

begin_define
define|#
directive|define
name|SQLITE_OMIT_DEPRECATED
end_define

begin_define
define|#
directive|define
name|SQLITE_API
value|static
end_define

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
operator|(
name|__GNUC_MINOR__
operator|>=
literal|6
operator|||
name|__APPLE_CC__
operator|)
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|__APPLE_CC__
operator|||
name|__GNUC_MINOR__
operator|>=
literal|6
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|push
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wunreachable-code"
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wunused-function"
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wcast-qual"
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wunused"
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wshadow"
end_pragma

begin_if
if|#
directive|if
name|__APPLE_CC__
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wshorten-64-to-32"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<Availability.h>
end_include

begin_if
if|#
directive|if
name|__MAC_OS_X_VERSION_MIN_REQUIRED
operator|<
literal|1060
end_if

begin_comment
comment|/*<libkern/OSAtomic.h> is included on OS X by sqlite3.c, and           on old systems (Leopard or older), it cannot be compiled           with -std=c89 because it uses inline. This is a work-around. */
end_comment

begin_define
define|#
directive|define
name|inline
value|__inline__
end_define

begin_include
include|#
directive|include
file|<libkern/OSAtomic.h>
end_include

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SQLITE_DEFAULT_FILE_PERMISSIONS
value|0666
end_define

begin_include
include|#
directive|include
file|<sqlite3.c>
end_include

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
operator|(
name|__GNUC_MINOR__
operator|>=
literal|6
operator|)
operator|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Expose the sqlite API vtable and the two missing functions */
end_comment

begin_decl_stmt
specifier|const
name|sqlite3_api_routines
modifier|*
specifier|const
name|svn_sqlite3__api_funcs
init|=
operator|&
name|sqlite3Apis
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
specifier|const
name|svn_sqlite3__api_initialize
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|sqlite3_initialize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
specifier|const
name|svn_sqlite3__api_config
argument_list|)
argument_list|(
name|int
argument_list|,
operator|...
argument_list|)
operator|=
name|sqlite3_config
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

