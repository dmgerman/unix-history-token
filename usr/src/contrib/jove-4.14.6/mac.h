begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* Macintosh related things. K. Mitchum 2/88 */
end_comment

begin_define
define|#
directive|define
name|NMENUS
value|6
end_define

begin_define
define|#
directive|define
name|NMENUITEMS
value|40
end_define

begin_comment
comment|/* This has GOT to be enough! */
end_comment

begin_typedef
typedef|typedef
name|data_obj
modifier|*
name|menumap
index|[
name|NMENUITEMS
index|]
typedef|;
end_typedef

begin_struct
struct|struct
name|menu
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|int
name|menu_id
decl_stmt|;
name|MenuHandle
name|Mn
decl_stmt|;
name|menumap
name|m
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|stat
block|{
name|int
name|st_dev
decl_stmt|;
comment|/* volume number */
name|long
name|st_ino
decl_stmt|;
comment|/* file number on volume */
name|dev_t
name|st_rdev
decl_stmt|;
name|off_t
name|st_size
decl_stmt|;
comment|/* logical end of file */
name|int
name|st_mode
decl_stmt|;
name|time_t
name|st_mtime
decl_stmt|;
comment|/* last modified */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_IFDIR
value|2
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_dcl
value|va_list va_alist;
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|l
parameter_list|)
value|{ (l) = (va_list)&va_alist; }
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|l
parameter_list|,
name|m
parameter_list|)
value|(((m*)((l) += sizeof(m)))[-1])
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|l
parameter_list|)
value|{ (l) = NULL; }
end_define

end_unit

