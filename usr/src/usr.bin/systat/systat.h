begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      systat.h     1.1     83/10/01     */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_include
include|#
directive|include
file|<sys/vm.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_decl_stmt
name|struct
name|nlist
name|nlst
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|p_times
block|{
name|short
name|pt_pid
decl_stmt|;
name|float
name|pt_pctcpu
decl_stmt|;
name|int
name|pt_uid
decl_stmt|;
name|int
name|pt_paddr
decl_stmt|;
name|struct
name|proc
modifier|*
name|pt_pp
decl_stmt|;
block|}
modifier|*
name|pt
struct|;
end_struct

begin_struct
struct|struct
name|procs
block|{
name|int
name|pid
decl_stmt|;
name|char
name|cmd
index|[
literal|16
index|]
decl_stmt|;
block|}
name|procs
index|[
literal|200
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|numprocs
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|users
block|{
name|int
name|k_uid
decl_stmt|;
name|char
name|k_name
index|[
literal|16
index|]
decl_stmt|;
block|}
name|known
index|[
literal|30
index|]
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
name|kmemf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|memf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|swapf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kmem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|swap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pcbpf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|argaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|col
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|nproc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|procp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|ccpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|lccpu
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|namp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|hostname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|numprocs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|numknown
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|naptime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxind
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|getw
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|float
name|total
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|factor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|lave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dellave
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|pidname
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
modifier|*
name|usrpt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
modifier|*
name|Usrptma
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|wnd
decl_stmt|;
end_decl_stmt

end_unit

