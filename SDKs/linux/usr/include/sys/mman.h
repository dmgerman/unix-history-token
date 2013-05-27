begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- limits.h - stub SDK header for compiler-rt -------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This is a stub SDK header file. This file is not part of the interface of  * this library nor an official version of the appropriate SDK header. It is  * intended only to stub the features of this header required by compiler-rt.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_MMAN_H__
end_ifndef

begin_define
define|#
directive|define
name|__SYS_MMAN_H__
end_define

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PROT_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PROT_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x04
end_define

begin_define
define|#
directive|define
name|MAP_SHARED
value|0x0001
end_define

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MAP_FILE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MAP_ANON
value|0x1000
end_define

begin_define
define|#
directive|define
name|MS_ASYNC
value|0x0001
end_define

begin_define
define|#
directive|define
name|MS_INVALIDATE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MS_SYNC
value|0x0010
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|mmap
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|prot
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|fd
parameter_list|,
name|long
name|long
name|offset
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nothrow__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|munmap
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nothrow__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|msync
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nothrow__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|mprotect
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|size_t
name|__len
parameter_list|,
name|int
name|__prot
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nothrow__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYS_MMAN_H__ */
end_comment

end_unit

