begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UNAME
end_ifdef

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
endif|UNAME
end_endif

begin_comment
comment|/*  * iconhost - return some sort of host name into the buffer pointed at  *  by hostname.  This code accommodates several different host name  *  fetching schemes.  */
end_comment

begin_macro
name|iconhost
argument_list|(
argument|hostname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|hostname
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|WHOHOST
comment|/*     * The host name is in /usr/include/whoami.h. (V7, 4.[01]bsd)     */
name|whohost
argument_list|(
name|hostname
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|WHOHOST
ifdef|#
directive|ifdef
name|UNAME
block|{
comment|/*     * Use the uname system call.  (System III& V)     */
name|struct
name|utsname
name|uts
decl_stmt|;
name|uname
argument_list|(
operator|&
name|uts
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|hostname
argument_list|,
name|uts
operator|.
name|nodename
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|UNAME
ifdef|#
directive|ifdef
name|GETHOST
comment|/*     * Use the gethostname system call.  (4.2bsd)     */
name|gethostname
argument_list|(
name|hostname
argument_list|,
name|MAXSTRING
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|GETHOST
ifdef|#
directive|ifdef
name|HOSTSTR
comment|/*     * The string constant HOSTSTR contains the host name.     */
name|strcpy
argument_list|(
name|hostname
argument_list|,
name|HOSTSTR
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|HOSTSTR
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|WHOHOST
end_ifdef

begin_define
define|#
directive|define
name|HDRFILE
value|"/usr/include/whoami.h"
end_define

begin_comment
comment|/*  * whohost - look for a line of the form  *  #define sysname "name"  * in HDRFILE and return the name.  */
end_comment

begin_macro
name|whohost
argument_list|(
argument|hostname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|hostname
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|FILE
modifier|*
name|fd
decl_stmt|;
name|fd
operator|=
name|fopen
argument_list|(
name|HDRFILE
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
name|NULL
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"Cannot open %s, no value for&host\n"
argument_list|,
name|HDRFILE
argument_list|)
expr_stmt|;
name|syserr
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
name|setbuf
argument_list|(
name|fd
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* each line in the file */
if|if
condition|(
name|fgets
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
name|fd
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"No #define for sysname in %s, no value for&host\n"
argument_list|,
name|HDRFILE
argument_list|)
expr_stmt|;
name|syserr
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sscanf
argument_list|(
name|buf
argument_list|,
literal|"#define sysname \"%[^\"]\""
argument_list|,
name|hostname
argument_list|)
operator|==
literal|1
condition|)
block|{
name|fclose
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
endif|WHOHOST
end_endif

end_unit

