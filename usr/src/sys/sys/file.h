begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	file.h	4.11	82/07/24	*/
end_comment

begin_comment
comment|/*  * Descriptor table entry.  * One for each kernel object.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|short
name|f_flag
decl_stmt|;
comment|/* see below */
name|short
name|f_type
decl_stmt|;
comment|/* descriptor type */
name|char
name|f_nbhow
decl_stmt|;
comment|/* state from dnblock */
name|char
name|f_sighow
decl_stmt|;
comment|/* state from dsignal */
name|short
name|f_count
decl_stmt|;
comment|/* reference count */
comment|/* begin XXX */
name|struct
name|inode
modifier|*
name|f_inode
decl_stmt|;
comment|/* inode */
union|union
block|{
struct|struct
name|f_in
block|{
name|off_t
name|fi_offset
decl_stmt|;
block|}
name|f_in
struct|;
struct|struct
name|f_so
block|{
name|struct
name|socket
modifier|*
name|fs_socket
decl_stmt|;
block|}
name|f_so
struct|;
block|}
name|f_un
union|;
define|#
directive|define
name|f_offset
value|f_un.f_in.fi_offset
define|#
directive|define
name|f_socket
value|f_un.f_so.fs_socket
comment|/* end XXX */
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
value|0x1
end_define

begin_comment
comment|/* descriptor read/receive'able */
end_comment

begin_define
define|#
directive|define
name|FWRITE
value|0x2
end_define

begin_comment
comment|/* descriptor write/send'able */
end_comment

begin_comment
comment|/* note: other flags for f_flag defined in fcntl.h */
end_comment

end_unit

