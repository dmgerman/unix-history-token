begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- stdio.h - stub SDK header for compiler-rt --------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This is a stub SDK header file. This file is not part of the interface of  * this library nor an official version of the appropriate SDK header. It is  * intended only to stub the features of this header required by compiler-rt.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDIO_H__
end_ifndef

begin_define
define|#
directive|define
name|__STDIO_H__
end_define

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|_IO_FILE
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|_IO_FILE
name|FILE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|_IO_FILE
modifier|*
name|stdin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_IO_FILE
modifier|*
name|stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_IO_FILE
modifier|*
name|stderr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* set file offset to offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* set file offset to current plus offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* set file offset to EOF plus offset */
end_comment

begin_function_decl
specifier|extern
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fopen
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fdopen
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fputc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|fwrite
parameter_list|(
specifier|const
name|void
modifier|*
specifier|restrict
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|fread
parameter_list|(
name|void
modifier|*
specifier|restrict
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|ftell
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fseek
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDIO_H__ */
end_comment

end_unit

