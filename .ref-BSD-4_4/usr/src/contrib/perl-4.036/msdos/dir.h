begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: dir.h,v $$Revision: 4.0.1.1 $$Date: 91/06/07 11:22:10 $  *  *    (C) Copyright 1987, 1990 Diomidis Spinellis.  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log:	dir.h,v $  * Revision 4.0.1.1  91/06/07  11:22:10  lwall  * patch4: new copyright notice  *   * Revision 4.0  91/03/20  01:34:20  lwall  * 4.0 baseline.  *   * Revision 3.0.1.1  90/03/27  16:07:08  lwall  * patch16: MSDOS support  *   * Revision 1.1  90/03/18  20:32:29  dds  * Initial revision  *  *  */
end_comment

begin_comment
comment|/*  * defines the type returned by the directory(3) functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DIR_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|__DIR_INCLUDED
end_define

begin_comment
comment|/*Directory entry size */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIRSIZ
end_ifdef

begin_undef
undef|#
directive|undef
name|DIRSIZ
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIRSIZ
parameter_list|(
name|rp
parameter_list|)
value|(sizeof(struct direct))
end_define

begin_comment
comment|/*  * Structure of a directory entry  */
end_comment

begin_struct
struct|struct
name|direct
block|{
name|ino_t
name|d_ino
decl_stmt|;
comment|/* inode number (not used by MS-DOS) */
name|int
name|d_namlen
decl_stmt|;
comment|/* Name length */
name|char
name|d_name
index|[
literal|13
index|]
decl_stmt|;
comment|/* file name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_dir_struc
block|{
comment|/* Structure used by dir operations */
name|char
modifier|*
name|start
decl_stmt|;
comment|/* Starting position */
name|char
modifier|*
name|curr
decl_stmt|;
comment|/* Current position */
name|struct
name|direct
name|dirstr
decl_stmt|;
comment|/* Directory structure to return */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_dir_struc
name|DIR
typedef|;
end_typedef

begin_comment
comment|/* Type returned by dir operations */
end_comment

begin_function_decl
name|DIR
modifier|*
name|cdecl
name|opendir
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|direct
modifier|*
name|readdir
parameter_list|(
name|DIR
modifier|*
name|dirp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|telldir
parameter_list|(
name|DIR
modifier|*
name|dirp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seekdir
parameter_list|(
name|DIR
modifier|*
name|dirp
parameter_list|,
name|long
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rewinddir
parameter_list|(
name|DIR
modifier|*
name|dirp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closedir
parameter_list|(
name|DIR
modifier|*
name|dirp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DIR_INCLUDED */
end_comment

end_unit

