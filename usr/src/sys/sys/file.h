begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	file.h	3.2	%G%	*/
end_comment

begin_comment
comment|/*  * One file structure is allocated  * for each open/creat/pipe call.  * Main use is to hold the read/write  * pointer associated with each open  * file.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|char
name|f_flag
decl_stmt|;
name|char
name|f_count
decl_stmt|;
comment|/* reference count */
name|struct
name|inode
modifier|*
name|f_inode
decl_stmt|;
comment|/* pointer to inode structure */
union|union
block|{
name|off_t
name|f_offset
decl_stmt|;
comment|/* read/write character pointer */
name|struct
name|chan
modifier|*
name|f_chan
decl_stmt|;
comment|/* mpx channel pointer */
block|}
name|f_un
union|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|file
name|file
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the file table itself */
end_comment

begin_function_decl
name|struct
name|file
modifier|*
name|getf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|file
modifier|*
name|falloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|FREAD
value|01
end_define

begin_define
define|#
directive|define
name|FWRITE
value|02
end_define

begin_define
define|#
directive|define
name|FPIPE
value|04
end_define

begin_define
define|#
directive|define
name|FMPX
value|010
end_define

begin_define
define|#
directive|define
name|FMPY
value|020
end_define

begin_define
define|#
directive|define
name|FMP
value|030
end_define

end_unit

