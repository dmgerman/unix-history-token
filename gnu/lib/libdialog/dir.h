begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * include file for dir.c  *  * Copyright (c) 1995, Marc van Kempen  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|DirList
block|{
comment|/* structure to hold the directory entries */
name|char
name|filename
index|[
name|MAXNAMLEN
index|]
decl_stmt|;
comment|/* together with the stat-info per file */
name|struct
name|stat
name|filestatus
decl_stmt|;
comment|/* filename, or the name to which it points */
name|int
name|link
decl_stmt|;
comment|/* is it a link ? */
name|char
modifier|*
name|linkname
decl_stmt|;
comment|/* the name of the file the link points to */
block|}
name|DirList
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|get_dir
parameter_list|(
name|char
modifier|*
name|dirname
parameter_list|,
name|char
modifier|*
name|fmask
parameter_list|,
name|DirList
modifier|*
modifier|*
name|dir
parameter_list|,
name|int
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_filenames
parameter_list|(
name|DirList
modifier|*
name|d
parameter_list|,
name|int
name|n
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|names
parameter_list|,
name|int
modifier|*
name|nf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FreeDir
parameter_list|(
name|DirList
modifier|*
name|d
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

end_unit

