begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#) dir.h 1.4 87/11/06   Public Domain.  *  *  A public domain implementation of BSD directory routines for  *  MS-DOS.  Written by Michael Rendell ({uunet,utai}michael@garfield),  *  August 1987  *  *  Enhanced and ported to OS/2 by Kai Uwe Rommel; added scandir() prototype  *  December 1989, February 1990  *  Change of MAXPATHLEN for HPFS, October 1990  */
end_comment

begin_define
define|#
directive|define
name|MAXNAMLEN
value|256
end_define

begin_define
define|#
directive|define
name|MAXPATHLEN
value|256
end_define

begin_define
define|#
directive|define
name|A_RONLY
value|0x01
end_define

begin_define
define|#
directive|define
name|A_HIDDEN
value|0x02
end_define

begin_define
define|#
directive|define
name|A_SYSTEM
value|0x04
end_define

begin_define
define|#
directive|define
name|A_LABEL
value|0x08
end_define

begin_define
define|#
directive|define
name|A_DIR
value|0x10
end_define

begin_define
define|#
directive|define
name|A_ARCHIVE
value|0x20
end_define

begin_struct
struct|struct
name|direct
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
comment|/* null terminated */
comment|/* nonstandard fields */
name|long
name|d_size
decl_stmt|;
comment|/* size in bytes */
name|unsigned
name|d_mode
decl_stmt|;
comment|/* DOS or OS/2 file attributes */
name|unsigned
name|d_time
decl_stmt|;
name|unsigned
name|d_date
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The fields d_size and d_mode are extensions by me (Kai Uwe Rommel).  * The find_first and find_next calls deliver this data without any extra cost.  * If this data is needed, these fields save a lot of extra calls to stat()  * (each stat() again performs a find_first call !).  */
end_comment

begin_struct
struct|struct
name|_dircontents
block|{
name|char
modifier|*
name|_d_entry
decl_stmt|;
name|long
name|_d_size
decl_stmt|;
name|unsigned
name|_d_mode
decl_stmt|,
name|_d_time
decl_stmt|,
name|_d_date
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

begin_decl_stmt
specifier|extern
name|int
name|attributes
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|DIR
modifier|*
name|opendir
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|direct
modifier|*
name|readdir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|seekdir
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|telldir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|closedir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
value|seekdir(dirp, 0L)
end_define

begin_function_decl
specifier|extern
name|int
name|scandir
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|direct
modifier|*
modifier|*
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|direct
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|direct
modifier|*
parameter_list|,
name|struct
name|direct
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getfmode
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setfmode
parameter_list|(
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

end_unit

