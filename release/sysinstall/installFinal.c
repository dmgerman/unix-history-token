begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $Id: installFinal.c,v 1.9 1995/10/22 21:38:10 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard& Coranth Gryphon.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the authors listed above  *	for the FreeBSD Project.  * 4. The names of the authors or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE FREEBSD PROJECT ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR THEIR PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_decl_stmt
specifier|static
name|DMenu
name|MenuSamba
init|=
block|{
name|DMENU_MULTIPLE_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Samba Services Menu"
block|,
literal|"This allows you to configure various aspects of your Samba server."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"Homes"
block|,
literal|"Make home directories available to users."
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"SAMBA_homes=YES"
block|,
literal|0
block|,
literal|0
block|,
name|dmenuVarCheck
block|}
block|,
block|{
literal|"Printers"
block|,
literal|"Allows for sharing of local printers."
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"SAMBA_printers=YES"
block|,
literal|0
block|,
literal|0
block|,
name|dmenuVarCheck
block|}
block|,
block|{
literal|"Export Paths"
block|,
literal|"Specify local directories to make available."
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"SAMBA_export=YES"
block|,
literal|0
block|,
literal|0
block|,
name|dmenuVarCheck
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These probably shouldn't be hard-coded, but making them options might prove to be even more confusing! */
end_comment

begin_define
define|#
directive|define
name|FTP_UID
value|14
end_define

begin_define
define|#
directive|define
name|FTP_NAME
value|"ftp"
end_define

begin_define
define|#
directive|define
name|FTP_GROUP
value|"operator"
end_define

begin_define
define|#
directive|define
name|FTP_COMMENT
value|"Anonymous FTP Admin"
end_define

begin_define
define|#
directive|define
name|SMB_CONF
value|"./smb.conf"
end_define

begin_comment
comment|/* Do any final network configuration hackery */
end_comment

begin_function
name|int
name|installNetworking
parameter_list|(
name|char
modifier|*
name|unused
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|tval
decl_stmt|;
name|char
name|tbuf
index|[
literal|256
index|]
decl_stmt|;
name|char
modifier|*
name|tptr
decl_stmt|;
name|FILE
modifier|*
name|fptr
decl_stmt|;
name|i
operator|=
name|RET_SUCCESS
expr_stmt|;
comment|/* Do we want to install and set up gated? */
if|if
condition|(
name|variable_get
argument_list|(
literal|"gated"
argument_list|)
condition|)
block|{
comment|/* Load gated package and maybe even seek to configure or explain it a little */
block|}
comment|/* Set up anonymous FTP access to this machine? */
if|if
condition|(
name|variable_get
argument_list|(
literal|"anon_ftp"
argument_list|)
condition|)
block|{
name|tptr
operator|=
name|msgGetInput
argument_list|(
literal|"/u"
argument_list|,
literal|"What directory should the ftp home be in?"
argument_list|)
expr_stmt|;
if|if
condition|(
name|tptr
operator|&&
operator|*
name|tptr
operator|&&
operator|(
name|tptr
index|[
literal|0
index|]
operator|==
literal|'/'
operator|)
condition|)
block|{
name|int
name|len
init|=
name|strlen
argument_list|(
name|tbuf
argument_list|)
decl_stmt|;
name|strcpy
argument_list|(
name|tbuf
argument_list|,
name|tptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|tbuf
index|[
name|len
operator|-
literal|1
index|]
operator|==
literal|'/'
condition|)
name|tbuf
index|[
name|len
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|vsystem
argument_list|(
literal|"adduser -uid %d -home %s -shell date -dotdir no -batch %s %s \"%s\" "
argument_list|,
name|FTP_UID
argument_list|,
name|tbuf
argument_list|,
name|FTP_NAME
argument_list|,
name|FTP_GROUP
argument_list|,
name|FTP_COMMENT
argument_list|)
condition|)
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|msgConfirm
argument_list|(
literal|"Unable to create FTP user!  Anonymous FTP setup failed."
argument_list|)
expr_stmt|;
name|i
operator|=
name|RET_FAIL
expr_stmt|;
block|}
else|else
block|{
name|vsystem
argument_list|(
literal|"mkdir %s/%s/pub"
argument_list|,
name|tbuf
argument_list|,
name|FTP_NAME
argument_list|)
expr_stmt|;
name|vsystem
argument_list|(
literal|"mkdir %s/%s/upload"
argument_list|,
name|tbuf
argument_list|,
name|FTP_NAME
argument_list|)
expr_stmt|;
name|vsystem
argument_list|(
literal|"chmod 0777 %s/%s/upload"
argument_list|,
name|tbuf
argument_list|,
name|FTP_NAME
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|msgConfirm
argument_list|(
literal|"Invalid Directory. Anonymous FTP will not be set up."
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Set this machine up as a web server? */
if|if
condition|(
name|variable_get
argument_list|(
literal|"apache_httpd"
argument_list|)
condition|)
block|{
name|i
operator|=
name|installApache
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
block|}
comment|/* Set this machine up as a Samba server? */
if|if
condition|(
name|variable_get
argument_list|(
literal|"samba"
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|dmenuOpenSimple
argument_list|(
operator|&
name|MenuSamba
argument_list|)
condition|)
name|i
operator|=
name|RET_FAIL
expr_stmt|;
else|else
block|{
name|fptr
operator|=
name|fopen
argument_list|(
literal|"/tmp/smb.conf"
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fptr
condition|)
block|{
name|strcpy
argument_list|(
name|tbuf
argument_list|,
literal|"FreeBSD - Samba %v"
argument_list|)
expr_stmt|;
if|if
condition|(
name|variable_get
argument_list|(
literal|"SAMBA_string"
argument_list|)
condition|)
block|{
name|tptr
operator|=
name|msgGetInput
argument_list|(
literal|"FreeBSD - Samba %%v"
argument_list|,
literal|"What should this server list as its description?\n"
literal|"Note that the \"%%v\" refers to the samba version number."
argument_list|)
expr_stmt|;
if|if
condition|(
name|tptr
operator|&&
operator|*
name|tptr
condition|)
name|strcpy
argument_list|(
name|tbuf
argument_list|,
name|tptr
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"[global]\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"comment = %s\n"
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"log file = /var/log/samba.log\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"dont descend = /dev,/proc,/root,/stand\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"printing = bsd\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"map archive = no\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"status = yes\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"public = yes\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"read only = no\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"preserve case = yes\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"strip dot = yes\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"security = share\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"guest ok = yes\n\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|variable_get
argument_list|(
literal|"SAMBA_homes"
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"[homes]\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"browseable = no\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"comment = User Home Directory\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"create mode = 0775\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"public = no\n\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|variable_get
argument_list|(
literal|"SAMBA_printers"
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"[printers]\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"path = /var/spool\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"comment = Printers\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"create mode = 0700\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"browseable = no\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"printable = yes\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"read only = yes\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"public = no\n\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|variable_get
argument_list|(
literal|"SAMBA_export"
argument_list|)
condition|)
block|{
for|for
control|(
name|tval
operator|=
literal|0
init|;
operator|!
name|tval
condition|;
name|tval
operator|=
name|msgYesNo
argument_list|(
literal|"Another?"
argument_list|)
control|)
block|{
name|tptr
operator|=
name|msgGetInput
argument_list|(
name|NULL
argument_list|,
literal|"What directory to export?"
argument_list|)
expr_stmt|;
if|if
condition|(
name|tptr
operator|&&
operator|*
name|tptr
operator|&&
operator|(
name|tptr
index|[
literal|0
index|]
operator|==
literal|'/'
operator|)
condition|)
block|{
name|int
name|len
init|=
name|strlen
argument_list|(
name|tbuf
argument_list|)
decl_stmt|;
name|strcpy
argument_list|(
name|tbuf
argument_list|,
name|tptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|tbuf
index|[
name|len
operator|-
literal|1
index|]
operator|==
literal|'/'
condition|)
name|tbuf
index|[
name|len
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|directoryExists
argument_list|(
name|tbuf
argument_list|)
condition|)
block|{
name|tptr
operator|=
name|msgGetInput
argument_list|(
name|pathBaseName
argument_list|(
name|tbuf
argument_list|)
argument_list|,
literal|"What do you want to call this share?"
argument_list|)
expr_stmt|;
if|if
condition|(
name|tptr
operator|&&
operator|*
name|tptr
condition|)
block|{
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"[%s]\npath = %s\n"
argument_list|,
name|tptr
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
name|tptr
operator|=
name|msgGetInput
argument_list|(
name|NULL
argument_list|,
literal|"Enter a short description of this share?"
argument_list|)
expr_stmt|;
if|if
condition|(
name|tptr
operator|&&
operator|*
name|tptr
condition|)
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"comment = %s\n"
argument_list|,
name|tptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|msgYesNo
argument_list|(
literal|"Do you want this share to be read only?"
argument_list|)
condition|)
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"read only = no\n\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|fptr
argument_list|,
literal|"read only = yes\n\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|msgConfirm
argument_list|(
literal|"Invalid Share Name."
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|msgConfirm
argument_list|(
literal|"Directory does not exist."
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* end if (tptr)	 */
block|}
comment|/* end for loop		 */
block|}
comment|/* end if (SAMBA_export) */
name|fclose
argument_list|(
name|fptr
argument_list|)
expr_stmt|;
name|vsystem
argument_list|(
literal|"mv -f /tmp/smb.conf %s"
argument_list|,
name|SMB_CONF
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|msgConfirm
argument_list|(
literal|"Unable to open temporary smb.conf file.\nSamba must be configured by hand."
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/* Set this machine up with a PC-NFS authentication server? */
if|if
condition|(
name|variable_get
argument_list|(
literal|"pcnfsd"
argument_list|)
condition|)
block|{
comment|/* Load and configure pcnfsd */
block|}
comment|/* If we're an NFS server, we need an exports file */
if|if
condition|(
name|variable_get
argument_list|(
literal|"nfs_server"
argument_list|)
operator|&&
operator|!
name|file_readable
argument_list|(
literal|"/etc/exports"
argument_list|)
condition|)
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|msgConfirm
argument_list|(
literal|"You have chosen to be an NFS server but have not yet configured\n"
literal|"the /etc/exports file.  You must configure this information before\n"
literal|"other hosts will be able to mount file systems from your machine.\n"
literal|"Press [ENTER] now to invoke an editor on /etc/exports"
argument_list|)
expr_stmt|;
name|vsystem
argument_list|(
literal|"echo '#The following example exports /usr to 3 machines named after ducks.'> /etc/exports"
argument_list|)
expr_stmt|;
name|vsystem
argument_list|(
literal|"echo '#/usr	huey louie dewie'>> /etc/exports"
argument_list|)
expr_stmt|;
name|vsystem
argument_list|(
literal|"echo>> /etc/exports"
argument_list|)
expr_stmt|;
name|systemExecute
argument_list|(
literal|"ee /etc/exports"
argument_list|)
expr_stmt|;
block|}
return|return
name|i
return|;
block|}
end_function

end_unit

