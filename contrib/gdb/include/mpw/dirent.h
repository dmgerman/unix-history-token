begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__dirent_h
end_ifndef

begin_define
define|#
directive|define
name|__dirent_h
end_define

begin_include
include|#
directive|include
file|"sys/dir.h"
end_include

begin_struct
struct|struct
name|dirent
block|{
name|long
name|d_ino
decl_stmt|;
comment|/* inode number of entry */
name|off_t
name|d_off
decl_stmt|;
comment|/* offset of disk directory entry */
name|unsigned
name|short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|char
name|d_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name of file */
block|}
struct|;
end_struct

begin_comment
comment|/* #define	DIRENTBASESIZE \ 	(((struct dirent *) 0)->d_name - (char *) 0) #define	DIRENTSIZE(namelen) \ 	((DIRENTBASESIZE + (namelen) + NBPW)& ~(NBPW - 1)) */
end_comment

begin_comment
comment|/* from Mips posix/dirent.h */
end_comment

begin_comment
comment|/* #undef rewinddir */
end_comment

begin_function_decl
specifier|extern
name|DIR
modifier|*
name|opendir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rewinddir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|closedir
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __dirent_h */
end_comment

end_unit

