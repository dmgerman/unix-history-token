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

begin_comment
comment|/* GCOV_PREFIX and GCOV_PREFIX_STRIP support */
end_comment

begin_comment
comment|/* Return the path prefix specified by GCOV_PREFIX environment variable.  * If GCOV_PREFIX_STRIP is also specified, the strip level (integer value)  * is returned via \c *PrefixStrip. The prefix length is stored in *PrefixLen.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|lprofGetPathPrefix
parameter_list|(
name|int
modifier|*
name|PrefixStrip
parameter_list|,
name|size_t
modifier|*
name|PrefixLen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Apply the path prefix specified in \c Prefix to path string in \c PathStr,  * and store the result to buffer pointed to by \c Buffer. If \c PrefixStrip  * is not zero, path prefixes are stripped from \c PathStr (the level of  * stripping is specified by \c PrefixStrip) before \c Prefix is added.  */
end_comment

begin_function_decl
name|void
name|lprofApplyPathPrefix
parameter_list|(
name|char
modifier|*
name|Dest
parameter_list|,
specifier|const
name|char
modifier|*
name|PathStr
parameter_list|,
specifier|const
name|char
modifier|*
name|Prefix
parameter_list|,
name|size_t
name|PrefixLen
parameter_list|,
name|int
name|PrefixStrip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns a pointer to the first occurrence of \c DIR_SEPARATOR char in  * the string \c Path, or NULL if the char is not found. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|lprofFindFirstDirSeparator
parameter_list|(
specifier|const
name|char
modifier|*
name|Path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns a pointer to the last occurrence of \c DIR_SEPARATOR char in  * the string \c Path, or NULL if the char is not found. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|lprofFindLastDirSeparator
parameter_list|(
specifier|const
name|char
modifier|*
name|Path
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* Temporarily suspend SIGKILL. Return value of 1 means a restore is needed.  * Other return values mean no restore is needed.  */
end_comment

begin_function_decl
name|int
name|lprofSuspendSigKill
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Restore previously suspended SIGKILL. */
end_comment

begin_function_decl
name|void
name|lprofRestoreSigKill
parameter_list|()
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

