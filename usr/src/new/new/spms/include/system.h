begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * System-dependent definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_define
define|#
directive|define
name|FILEXIST
parameter_list|(
name|file
parameter_list|)
value|(access(file,0) ? 0 : 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|V4BSD
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_define
define|#
directive|define
name|CREATE
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|open(name,flags|FCREAT,mode)
end_define

begin_define
define|#
directive|define
name|FORK
parameter_list|()
value|vfork()
end_define

begin_define
define|#
directive|define
name|MK_DIR
parameter_list|(
name|name
parameter_list|)
value|((mkdir(name, 0777) != 0)?pperror(name),1:0)
end_define

begin_define
define|#
directive|define
name|OPEN
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|open(name,flags,mode)
end_define

begin_define
define|#
directive|define
name|RENAME
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
value|rename(from,to)
end_define

begin_define
define|#
directive|define
name|RM_DIR
parameter_list|(
name|name
parameter_list|)
value|rm_dir(name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|O_RDONLY
value|000
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|001
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|002
end_define

begin_define
define|#
directive|define
name|CREATE
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|creat(name,mode)
end_define

begin_define
define|#
directive|define
name|FORK
parameter_list|()
value|fork()
end_define

begin_define
define|#
directive|define
name|MK_DIR
parameter_list|(
name|name
parameter_list|)
value|mk_dir(name)
end_define

begin_define
define|#
directive|define
name|OPEN
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|open(name,flags)
end_define

begin_define
define|#
directive|define
name|RENAME
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
value|unlink(to); link(from,to); unlink(from)
end_define

begin_define
define|#
directive|define
name|RM_DIR
parameter_list|(
name|name
parameter_list|)
value|rm_dir(name)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

