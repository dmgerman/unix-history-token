begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)msd_dir.h 1.4 87/11/06	Public Domain.  *  *  A public domain implementation of BSD directory routines for  *  MS-DOS.  Written by Michael Rendell ({uunet,utai}michael@garfield),  *  August 1897  */
end_comment

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
value|seekdir(dirp, 0L)
end_define

begin_define
define|#
directive|define
name|MAXNAMLEN
value|12
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_typedef
typedef|typedef
name|int
name|ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|dev_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|dirent
block|{
name|ino_t
name|d_ino
decl_stmt|;
comment|/* a bit of a farce */
name|int
name|d_reclen
decl_stmt|;
comment|/* more farce */
name|int
name|d_namlen
decl_stmt|;
comment|/* length of d_name */
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* garentee null termination */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_dircontents
block|{
name|char
modifier|*
name|_d_entry
decl_stmt|;
name|struct
name|_dircontents
modifier|*
name|_d_next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_dirdesc
block|{
name|int
name|dd_id
decl_stmt|;
comment|/* uniquely identify each open directory */
name|long
name|dd_loc
decl_stmt|;
comment|/* where we are in directory entry is this */
name|struct
name|_dircontents
modifier|*
name|dd_contents
decl_stmt|;
comment|/* pointer to contents of dir */
name|struct
name|_dircontents
modifier|*
name|dd_cp
decl_stmt|;
comment|/* pointer to current position */
block|}
name|DIR
typedef|;
end_typedef

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
name|seekdir
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
name|closedir
parameter_list|()
function_decl|;
end_function_decl

end_unit

