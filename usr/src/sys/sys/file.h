begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	file.h	4.8	81/10/17	*/
end_comment

begin_comment
comment|/*  * One file structure is allocated  * for each open/creat/pipe call.  * Main use is to hold the read/write  * pointer associated with each open  * file.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|short
name|f_flag
decl_stmt|;
name|short
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
name|port
modifier|*
name|f_port
decl_stmt|;
comment|/* port (used for pipes, too) */
ifdef|#
directive|ifdef
name|CHAOS
name|struct
name|connection
modifier|*
name|f_conn
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BBNNET
name|struct
name|ucb
modifier|*
name|f_ucb
decl_stmt|;
comment|/* net connection block pointer */
endif|#
directive|endif
endif|BBNNET
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
name|struct
name|file
modifier|*
name|file
decl_stmt|,
modifier|*
name|fileNFILE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the file table itself */
end_comment

begin_decl_stmt
name|int
name|nfile
decl_stmt|;
end_decl_stmt

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
name|FPORT
value|040
end_define

begin_define
define|#
directive|define
name|FNET
value|0100
end_define

begin_comment
comment|/* this is a network entry */
end_comment

end_unit

