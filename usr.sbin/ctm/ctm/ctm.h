begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

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
file|<sys/file.h>
end_include

begin_comment
comment|/*  * We redefine the names to make it look nice...  */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"2.0"
end_define

begin_define
define|#
directive|define
name|MAXSIZE
value|(1024*1024*10)
end_define

begin_comment
comment|/* The fields... */
end_comment

begin_define
define|#
directive|define
name|CTM_F_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|CTM_F_Name
value|0x01
end_define

begin_define
define|#
directive|define
name|CTM_F_Uid
value|0x02
end_define

begin_define
define|#
directive|define
name|CTM_F_Gid
value|0x03
end_define

begin_define
define|#
directive|define
name|CTM_F_Mode
value|0x04
end_define

begin_define
define|#
directive|define
name|CTM_F_MD5
value|0x05
end_define

begin_define
define|#
directive|define
name|CTM_F_Count
value|0x06
end_define

begin_define
define|#
directive|define
name|CTM_F_Bytes
value|0x07
end_define

begin_comment
comment|/* The qualifiers... */
end_comment

begin_define
define|#
directive|define
name|CTM_Q_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|CTM_Q_Name_File
value|0x0100
end_define

begin_define
define|#
directive|define
name|CTM_Q_Name_Dir
value|0x0200
end_define

begin_define
define|#
directive|define
name|CTM_Q_Name_New
value|0x0400
end_define

begin_define
define|#
directive|define
name|CTM_Q_MD5_After
value|0x0100
end_define

begin_define
define|#
directive|define
name|CTM_Q_MD5_Before
value|0x0200
end_define

begin_define
define|#
directive|define
name|CTM_Q_MD5_Chunk
value|0x0400
end_define

begin_struct
struct|struct
name|CTM_Syntax
block|{
name|char
modifier|*
name|Key
decl_stmt|;
name|int
modifier|*
name|List
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|CTM_Syntax
name|Syntax
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|Malloc
value|malloc
end_define

begin_define
define|#
directive|define
name|Free
value|free
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|EXTERN
end_ifndef

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|Version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|Name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|Nbr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|TimeStamp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|Prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|FileName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|BaseDir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|TmpDir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|Verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Paranoid -- Just in case they should be after us...  *  0 not at all.  *  1 normal.  *  2 somewhat.  *  3 you bet!.  *  * Verbose -- What to tell mom...  *  0 Nothing which wouldn't surprise.  *  1 Normal.   *  2 Show progress '.'.  *  3 Show progress names, and actions.  *  4 even more...  *  and so on  */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Paranoid
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|String
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Fatal_
parameter_list|(
name|int
name|ln
parameter_list|,
name|char
modifier|*
name|fn
parameter_list|,
name|char
modifier|*
name|kind
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|Fatal
parameter_list|(
name|foo
parameter_list|)
value|Fatal_(__LINE__,__FILE__,foo)
end_define

begin_define
define|#
directive|define
name|Assert
parameter_list|()
value|Fatal_(__LINE__,__FILE__,"Assert failed.")
end_define

begin_define
define|#
directive|define
name|WRONG
value|{Assert(); return 1;}
end_define

begin_function_decl
name|u_char
modifier|*
name|Ffield
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
name|MD5_CTX
modifier|*
name|ctx
parameter_list|,
name|u_char
name|term
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Fbytecnt
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
name|MD5_CTX
modifier|*
name|ctx
parameter_list|,
name|u_char
name|term
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
modifier|*
name|Fdata
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
name|int
name|u_chars
parameter_list|,
name|MD5_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GETFIELD
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
value|if(!((p)=Ffield(fd,&ctx,(q)))) return 1
end_define

begin_define
define|#
directive|define
name|GETFIELDCOPY
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
value|if(!((p)=Ffield(fd,&ctx,(q)))) return 1; else p=String(p)
end_define

begin_define
define|#
directive|define
name|GETBYTECNT
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
value|if(0>((p)= Fbytecnt(fd,&ctx,(q)))) return 1
end_define

begin_define
define|#
directive|define
name|GETDATA
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
value|if(!((p) = Fdata(fd,(q),&ctx))) return 1
end_define

begin_function_decl
name|int
name|Pass1
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Pass2
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Pass3
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|)
function_decl|;
end_function_decl

end_unit

