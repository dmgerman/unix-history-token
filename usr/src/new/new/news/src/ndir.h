begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California  */
end_comment

begin_comment
comment|/* @(#)ndir.h 4.4 3/30/82 */
end_comment

begin_comment
comment|/*  * This sets the "page size" for directories.  * Requirements are DEV_BSIZE<= DIRBLKSIZ<= MINBSIZE with  * DIRBLKSIZ a power of two.  * Dennis Ritchie feels that directory pages should be atomic  * operations to the disk, so we use DEV_BSIZE.  */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|512
end_define

begin_comment
comment|/*  * This limits the directory name length. Its main constraint  * is that it appears twice in the user structure. (u. area)  */
end_comment

begin_define
define|#
directive|define
name|MAXNAMLEN
value|255
end_define

begin_struct
struct|struct
name|direct
block|{
name|ino_t
name|d_ino
decl_stmt|;
name|short
name|d_reclen
decl_stmt|;
name|short
name|d_namlen
decl_stmt|;
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* typically shorter */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_dirdesc
block|{
name|int
name|dd_fd
decl_stmt|;
name|long
name|dd_loc
decl_stmt|;
name|long
name|dd_size
decl_stmt|;
name|char
name|dd_buf
index|[
name|DIRBLKSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * useful macros.  */
end_comment

begin_undef
undef|#
directive|undef
name|DIRSIZ
end_undef

begin_define
define|#
directive|define
name|DIRSIZ
parameter_list|(
name|dp
parameter_list|)
define|\
value|((sizeof(struct direct) - MAXNAMLEN + (dp)->d_namlen + sizeof(ino_t) - 1)&\     ~(sizeof(ino_t) - 1))
end_define

begin_typedef
typedef|typedef
name|struct
name|_dirdesc
name|DIR
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * functions defined on directories  */
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
name|direct
modifier|*
name|readdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|telldir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|seekdir
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
value|seekdir((dirp), 0)
end_define

begin_function_decl
specifier|extern
name|void
name|closedir
parameter_list|()
function_decl|;
end_function_decl

end_unit

