begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2002 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_STATVFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_STATVFS_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_comment
comment|/*  * POSIX says we must define the fsblkcnt_t and fsfilcnt_t types here.  * Note that these must be unsigned integer types, so we have to be  * careful in converting the signed statfs members to the unsigned  * statvfs members.  (Well, actually, we don't -- see below -- but  * a quality implementation should.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FSBLKCNT_T_DECLARED
end_ifndef

begin_comment
comment|/* always declared together */
end_comment

begin_typedef
typedef|typedef
name|__fsblkcnt_t
name|fsblkcnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__fsfilcnt_t
name|fsfilcnt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_FSBLKCNT_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The difference between `avail' and `free' is that `avail' represents  * space available to unprivileged processes, whereas `free' includes all  * unallocated space, including that reserved for privileged processes.  * Or at least, that's the most useful interpretation.  (According to  * the letter of the standard, this entire interface is completely  * unspecified!)  */
end_comment

begin_struct
struct|struct
name|statvfs
block|{
name|fsblkcnt_t
name|f_bavail
decl_stmt|;
comment|/* Number of blocks */
name|fsblkcnt_t
name|f_bfree
decl_stmt|;
name|fsblkcnt_t
name|f_blocks
decl_stmt|;
name|fsfilcnt_t
name|f_favail
decl_stmt|;
comment|/* Number of files (e.g., inodes) */
name|fsfilcnt_t
name|f_ffree
decl_stmt|;
name|fsfilcnt_t
name|f_files
decl_stmt|;
name|unsigned
name|long
name|f_bsize
decl_stmt|;
comment|/* Size of blocks counted above */
name|unsigned
name|long
name|f_flag
decl_stmt|;
name|unsigned
name|long
name|f_frsize
decl_stmt|;
comment|/* Size of fragments */
name|unsigned
name|long
name|f_fsid
decl_stmt|;
comment|/* Not meaningful */
name|unsigned
name|long
name|f_namemax
decl_stmt|;
comment|/* Same as pathconf(_PC_NAME_MAX) */
block|}
struct|;
end_struct

begin_comment
comment|/* flag bits for f_flag: */
end_comment

begin_define
define|#
directive|define
name|ST_RDONLY
value|0x1
end_define

begin_define
define|#
directive|define
name|ST_NOSUID
value|0x2
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|fstatvfs
parameter_list|(
name|int
parameter_list|,
name|struct
name|statvfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|statvfs
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|struct
name|statvfs
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_STATVFS_H_ */
end_comment

end_unit

