begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FCntl.h -- faccess(), fcntl(), and open() mode flags  *  * Portions copyright American Telephone& Telegraph  * Used with permission, Apple Computer Inc. (1985,1988,1990,1992)  * All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FCNTL__
end_ifndef

begin_define
define|#
directive|define
name|__FCNTL__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__TYPES__
end_ifndef

begin_include
include|#
directive|include
file|<Types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	For use by lseek():  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDIO__
end_ifndef

begin_comment
comment|/* these defns exactly paralled in StdIO.h for fseek() */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * faccess() commands; for general use  */
end_comment

begin_comment
comment|/* 'd' => "directory" ops */
end_comment

begin_define
define|#
directive|define
name|F_DELETE
value|(('d'<<8)|0x01)
end_define

begin_define
define|#
directive|define
name|F_RENAME
value|(('d'<<8)|0x02)
end_define

begin_comment
comment|/*  * more faccess() commands; for use only by MPW tools  */
end_comment

begin_define
define|#
directive|define
name|F_OPEN
value|(('d'<<8)|0x00)
end_define

begin_comment
comment|/* reserved for operating system use */
end_comment

begin_comment
comment|/* 'e' => "editor" ops */
end_comment

begin_define
define|#
directive|define
name|F_GTABINFO
value|(('e'<<8)|0x00)
end_define

begin_comment
comment|/* get tab offset for file */
end_comment

begin_define
define|#
directive|define
name|F_STABINFO
value|(('e'<<8)|0x01)
end_define

begin_comment
comment|/* set 	"	"		"	"  */
end_comment

begin_define
define|#
directive|define
name|F_GFONTINFO
value|(('e'<<8)|0x02)
end_define

begin_comment
comment|/* get font number and size for file */
end_comment

begin_define
define|#
directive|define
name|F_SFONTINFO
value|(('e'<<8)|0x03)
end_define

begin_comment
comment|/* set 	"		"	"	"	"	" 	 */
end_comment

begin_define
define|#
directive|define
name|F_GPRINTREC
value|(('e'<<8)|0x04)
end_define

begin_comment
comment|/* get print record for file */
end_comment

begin_define
define|#
directive|define
name|F_SPRINTREC
value|(('e'<<8)|0x05)
end_define

begin_comment
comment|/* set 	"		"	"	" 	 */
end_comment

begin_define
define|#
directive|define
name|F_GSELINFO
value|(('e'<<8)|0x06)
end_define

begin_comment
comment|/* get selection information for file */
end_comment

begin_define
define|#
directive|define
name|F_SSELINFO
value|(('e'<<8)|0x07)
end_define

begin_comment
comment|/* set		"		"		"		" */
end_comment

begin_define
define|#
directive|define
name|F_GWININFO
value|(('e'<<8)|0x08)
end_define

begin_comment
comment|/* get current window position */
end_comment

begin_define
define|#
directive|define
name|F_SWININFO
value|(('e'<<8)|0x09)
end_define

begin_comment
comment|/* set	"		"		" 	   */
end_comment

begin_define
define|#
directive|define
name|F_GSCROLLINFO
value|(('e'<<8)|0x0A)
end_define

begin_comment
comment|/* get scroll information */
end_comment

begin_define
define|#
directive|define
name|F_SSCROLLINFO
value|(('e'<<8)|0x0B)
end_define

begin_comment
comment|/* set    "   		"  	  */
end_comment

begin_define
define|#
directive|define
name|F_GMARKER
value|(('e'<<8)|0x0D)
end_define

begin_comment
comment|/* Get Marker */
end_comment

begin_define
define|#
directive|define
name|F_SMARKER
value|(('e'<<8)|0x0C)
end_define

begin_comment
comment|/* Set   " 	  */
end_comment

begin_define
define|#
directive|define
name|F_GSAVEONCLOSE
value|(('e'<<8)|0x0F)
end_define

begin_comment
comment|/* Get Save on close */
end_comment

begin_define
define|#
directive|define
name|F_SSAVEONCLOSE
value|(('e'<<8)|0x0E)
end_define

begin_comment
comment|/* Set   "	 "	 " 	 */
end_comment

begin_comment
comment|/*  *	argument structures used by various faccess() commands  */
end_comment

begin_struct
struct|struct
name|MarkElement
block|{
name|int
name|start
decl_stmt|;
comment|/* start position of mark */
name|int
name|end
decl_stmt|;
comment|/* end position */
name|unsigned
name|char
name|charCount
decl_stmt|;
comment|/* number of chars in mark name */
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|/* mark name */
block|}
struct|;
end_struct

begin_comment
comment|/* note: marker names may be up to 64 characters long */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|MarkElement
name|MarkElement
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|SelectionRecord
block|{
name|long
name|startingPos
decl_stmt|;
name|long
name|endingPos
decl_stmt|;
name|long
name|displayTop
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|SelectionRecord
name|SelectionRecord
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Mode values accessible to open()  */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_comment
comment|/* Bits 0 and 1 are used internally */
end_comment

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_comment
comment|/* Values 0..2 are historical */
end_comment

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_comment
comment|/* NOTE: it goes 0, 1, 2, *!* 8, 16, 32, ... */
end_comment

begin_define
define|#
directive|define
name|O_APPEND
value|(1<< 3)
end_define

begin_comment
comment|/* append (writes guaranteed at the end) */
end_comment

begin_define
define|#
directive|define
name|O_RSRC
value|(1<< 4)
end_define

begin_comment
comment|/* Open the resource fork */
end_comment

begin_define
define|#
directive|define
name|O_ALIAS
value|(1<< 5)
end_define

begin_comment
comment|/* Open alias file */
end_comment

begin_define
define|#
directive|define
name|O_CREAT
value|(1<< 8)
end_define

begin_comment
comment|/* Open with file create */
end_comment

begin_define
define|#
directive|define
name|O_TRUNC
value|(1<< 9)
end_define

begin_comment
comment|/* Open with truncation */
end_comment

begin_define
define|#
directive|define
name|O_EXCL
value|(1<<10)
end_define

begin_comment
comment|/* w/ O_CREAT:  Exclusive "create-only" */
end_comment

begin_define
define|#
directive|define
name|O_BINARY
value|(1<<11)
end_define

begin_comment
comment|/* Open as a binary stream */
end_comment

begin_define
define|#
directive|define
name|O_NRESOLVE
value|(1<<14)
end_define

begin_comment
comment|/* Don't resolve any aliases */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  *		function prototypes  */
name|int
name|close
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
name|creat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|dup
parameter_list|(
name|int
name|filedes
parameter_list|)
function_decl|;
comment|/* OBSOLETE: fcntl(filedes, F_DUPFD, 0) is preferred */
name|int
name|faccess
parameter_list|(
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
name|int
name|fcntl
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|long
name|lseek
parameter_list|(
name|int
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|int
name|read
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
name|int
name|unlink
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * fcntl() commands  */
end_comment

begin_define
define|#
directive|define
name|F_DUPFD
value|0
end_define

begin_comment
comment|/* Duplicate files (file descriptor) */
end_comment

begin_endif
endif|#
directive|endif
endif|__FCNTL__
end_endif

end_unit

