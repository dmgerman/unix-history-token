begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- InstrProfilingUtil.h - Support library for PGO instrumentation -----===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROFILE_INSTRPROFILINGUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|PROFILE_INSTRPROFILINGUTIL_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*! \brief Create a directory tree. */
end_comment

begin_function_decl
name|void
name|__llvm_profile_recursive_mkdir
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*! Open file \c Filename for read+write with write  * lock for exclusive access. The caller will block  * if the lock is already held by another process. */
end_comment

begin_function_decl
name|FILE
modifier|*
name|lprofOpenFileEx
parameter_list|(
specifier|const
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PS4 doesn't have getenv. Define a shim. */
end_comment

begin_if
if|#
directive|if
name|__ORBIS__
end_if

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if __ORBIS__ */
end_comment

begin_function_decl
name|int
name|lprofGetHostName
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|,
name|int
name|Len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|lprofBoolCmpXchg
parameter_list|(
name|void
modifier|*
modifier|*
name|Ptr
parameter_list|,
name|void
modifier|*
name|OldV
parameter_list|,
name|void
modifier|*
name|NewV
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|lprofPtrFetchAdd
parameter_list|(
name|void
modifier|*
modifier|*
name|Mem
parameter_list|,
name|long
name|ByteIncr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILE_INSTRPROFILINGUTIL_H */
end_comment

end_unit

