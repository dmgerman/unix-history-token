begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************* *                                                                  * *    File: CIFPLOT/fill.c                                          * *    Written by Dan Fitzpatrick& Dennis Wellborne                 * *    copyright 1980 -- Regents of the University of California     * *                                                                  * ********************************************************************/
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"globals.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_include
include|#
directive|include
file|"out_structs.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<sys/vcmd.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|plotmd
index|[]
init|=
block|{
name|VPLOT
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prtmd
index|[]
init|=
block|{
name|VPRINT
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stat
name|stbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|offline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Lock
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tail
init|=
literal|"a"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* letter appended to temp file name for uniqueness */
end_comment

begin_decl_stmt
name|int
name|NormalSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|StartNextPlot
decl_stmt|;
end_decl_stmt

begin_function_decl
name|IMPORT
name|char
modifier|*
name|Concat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|IMPORT
name|char
modifier|*
name|getlogin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|IMPORT
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|IMPORT
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NOLINES
value|32
end_define

begin_define
define|#
directive|define
name|VLIMIT
value|2112
end_define

begin_define
define|#
directive|define
name|VMAX
value|2000
end_define

begin_define
define|#
directive|define
name|VEXTRA
value|2100
end_define

begin_define
define|#
directive|define
name|VMIN
value|0
end_define

begin_define
define|#
directive|define
name|VRESOL
value|200.0
end_define

begin_define
define|#
directive|define
name|WLIMIT
value|7040
end_define

begin_define
define|#
directive|define
name|WMAX
value|7000
end_define

begin_define
define|#
directive|define
name|WEXTRA
value|7030
end_define

begin_define
define|#
directive|define
name|WMIN
value|0
end_define

begin_define
define|#
directive|define
name|WRESOL
value|200.0
end_define

begin_define
define|#
directive|define
name|HLIMIT
value|704
end_define

begin_define
define|#
directive|define
name|HMAX
value|700
end_define

begin_define
define|#
directive|define
name|HMIN
value|0
end_define

begin_define
define|#
directive|define
name|HRESOL
value|10.0
end_define

begin_define
define|#
directive|define
name|LOCK
value|"/usr/spool/vpd/lock"
end_define

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/vp0"
end_define

begin_define
define|#
directive|define
name|NAME
value|"Versatec"
end_define

begin_define
define|#
directive|define
name|DAEMON
value|"/usr/lib/vpd"
end_define

begin_define
define|#
directive|define
name|VDUMP
value|"/vb/grad/fitz/cif/newprogs/vdump"
end_define

begin_decl_stmt
name|int
name|xmax
decl_stmt|,
name|xlimit
decl_stmt|,
name|xmin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|real
name|resolution
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|heading
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FromMask
value|( 0xffffff00 | (0xff>> (from& 0x07)))<< (from& 0x18)
end_define

begin_define
define|#
directive|define
name|ToMask
value|(~((0xffffff00 | (0xff>> (to& 0x07)))<< (to& 0x18)))
end_define

begin_decl_stmt
name|char
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|filedesc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|OutBuf
decl_stmt|,
modifier|*
name|ScanLine
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|NoLine
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|int
name|from
decl_stmt|,
name|to
decl_stmt|;
name|printf
argument_list|(
literal|"int fromMask[32] = {\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|from
operator|=
literal|0
init|;
name|from
operator|<
literal|32
condition|;
name|from
operator|++
control|)
name|printf
argument_list|(
literal|"\t0x%x,\n"
argument_list|,
name|FromMask
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t};\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int toMask[32] = {\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|to
operator|=
literal|0
init|;
name|to
operator|<
literal|32
condition|;
name|to
operator|++
control|)
name|printf
argument_list|(
literal|"\t0x%x,\n"
argument_list|,
name|ToMask
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t};\n\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

