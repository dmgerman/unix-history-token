begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Mkmf definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Buffer sizes  */
end_comment

begin_define
define|#
directive|define
name|ANSWERBUFSIZE
value|256
end_define

begin_comment
comment|/* interactive answer buffer size */
end_comment

begin_define
define|#
directive|define
name|INCLUDETABLESIZE
value|127
end_define

begin_comment
comment|/* include file table size */
end_comment

begin_define
define|#
directive|define
name|MACRODEFSIZE
value|1024
end_define

begin_comment
comment|/* macro definition body size */
end_comment

begin_define
define|#
directive|define
name|MACRONAMSIZE
value|32
end_define

begin_comment
comment|/* macro definition name size */
end_comment

begin_define
define|#
directive|define
name|MDEFTABLESIZE
value|127
end_define

begin_comment
comment|/* macro definition table size */
end_comment

begin_define
define|#
directive|define
name|SFXTABSIZE
value|256
end_define

begin_comment
comment|/* suffix table size */
end_comment

begin_define
define|#
directive|define
name|SUFFIXSIZE
value|16
end_define

begin_comment
comment|/* suffix size */
end_comment

begin_comment
comment|/*  * Predefined macro names  */
end_comment

begin_define
define|#
directive|define
name|MCFLAGS
value|"CFLAGS"
end_define

begin_define
define|#
directive|define
name|MDESTDIR
value|"DEST"
end_define

begin_define
define|#
directive|define
name|MEXTERNALS
value|"EXTHDRS"
end_define

begin_define
define|#
directive|define
name|MFFLAGS
value|"FFLAGS"
end_define

begin_define
define|#
directive|define
name|MHEADERS
value|"HDRS"
end_define

begin_define
define|#
directive|define
name|MLIBLIST
value|"LIBS"
end_define

begin_define
define|#
directive|define
name|MLIBRARY
value|"LIBRARY"
end_define

begin_define
define|#
directive|define
name|MMAKEFILE
value|"MAKEFILE"
end_define

begin_define
define|#
directive|define
name|MOBJECTS
value|"OBJS"
end_define

begin_define
define|#
directive|define
name|MPFLAGS
value|"PFLAGS"
end_define

begin_define
define|#
directive|define
name|MPROGRAM
value|"PROGRAM"
end_define

begin_define
define|#
directive|define
name|MSOURCE
value|"SRCS"
end_define

begin_define
define|#
directive|define
name|MSUFFIX
value|"SUFFIX"
end_define

begin_comment
comment|/*  * Predefined macro values  */
end_comment

begin_define
define|#
directive|define
name|VUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|VREADONLY
value|1
end_define

begin_define
define|#
directive|define
name|VREADWRITE
value|2
end_define

begin_define
define|#
directive|define
name|VLIBRARY
value|3
end_define

begin_define
define|#
directive|define
name|VPROGRAM
value|4
end_define

begin_define
define|#
directive|define
name|VDESTDIR
value|5
end_define

begin_comment
comment|/*  * Include statement styles  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_C
value|'C'
end_define

begin_comment
comment|/* #include "file" */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_FORTRAN
value|'F'
end_define

begin_comment
comment|/* include "file" or #include "file" */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_PASCAL
value|'P'
end_define

begin_comment
comment|/* #include "file" */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_NONE
value|0
end_define

begin_comment
comment|/* no include file */
end_comment

end_unit

