begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * File system table, see fstab (5)  *  * Used by dump, mount, umount, swapon, fsck, df, ...  *  * The fs_spec field is the block special name.  * Programs that want to use the character special name must  * create that name by prepending a 'r' after the right most slash.  */
end_comment

begin_define
define|#
directive|define
name|FSTAB
value|"/etc/fstab"
end_define

begin_define
define|#
directive|define
name|FSNMLG
value|32
end_define

begin_define
define|#
directive|define
name|FSTABFMT
value|"%32s:%32s:%2s:%d:%d\n"
end_define

begin_define
define|#
directive|define
name|FSTABARG
parameter_list|(
name|p
parameter_list|)
value|(p)->fs_spec, (p)->fs_file, \ 			(p)->fs_type,&(p)->fs_freq,&(p)->fs_passno
end_define

begin_define
define|#
directive|define
name|FSTABNARGS
value|5
end_define

begin_define
define|#
directive|define
name|FSTAB_RW
value|"rw"
end_define

begin_comment
comment|/* read write device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_RO
value|"ro"
end_define

begin_comment
comment|/* read only device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_SW
value|"sw"
end_define

begin_comment
comment|/* swap device */
end_comment

begin_define
define|#
directive|define
name|FSTAB_XX
value|"xx"
end_define

begin_comment
comment|/* ignore totally */
end_comment

begin_struct
struct|struct
name|fstab
block|{
name|char
name|fs_spec
index|[
name|FSNMLG
index|]
decl_stmt|;
comment|/* block special device name */
name|char
name|fs_file
index|[
name|FSNMLG
index|]
decl_stmt|;
comment|/* file system path prefix */
name|char
name|fs_type
index|[
literal|3
index|]
decl_stmt|;
comment|/* rw,ro,sw or xx */
name|int
name|fs_freq
decl_stmt|;
comment|/* dump frequency, in days */
name|int
name|fs_passno
decl_stmt|;
comment|/* pass number on parallel dump */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|fstab
modifier|*
name|getfsent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fstab
modifier|*
name|getfsspec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fstab
modifier|*
name|getfsfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setfsent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|endfsent
parameter_list|()
function_decl|;
end_function_decl

end_unit

