begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tips.c */
end_comment

begin_comment
comment|/*  $RCSfile: tips.c,v $  *  $Revision: 14020.11 $  *  $Date: 93/05/21 05:44:39 $  */
end_comment

begin_include
include|#
directive|include
file|"sys.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_TIPS
end_ifndef

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_comment
comment|/* Make sure that the indentations are spaces, not tabs.  * Try newform -i-4< tips.c> tips.c.new  *  * Always add new tips right above the last one.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|tiplist
index|[]
init|=
block|{
literal|"Have you tried typing 'open' by itself lately?"
block|,
literal|"If you don't want a .ncrecent file in your home directory, put the \n\      command '#unset recent-list' in your .ncftprc file."
block|,
literal|"pseudo-filename-completion is supported in some commands.  To use it,\n\      use a wildcard expression that will match exactly one file.  I.e., if you\n\      want to fetch obnoxiouslylongfilename.zip, try 'get obn*.zip.'  Note that\n\      you can't use the cd command with this feature (yet)."
block|,
literal|"You don't need to type the exact site name with open.  If a site is in\n\      your .ncftprc or the recent-file (.ncrecent), just type a unique\n\      abbreviation (substring really).   I.e. 'open wuar' if you have the site\n\      wuarchive.wustl.edu in your rc or recent-file."
block|,
literal|"You can put set commands in your .ncftprc, by adding lines such\n\      as '#set local-dir /usr/tmp' to the file, which will be run at startup."
block|,
literal|"Use the .ncftprc file to set variables at startup and to add sites that \n\      need init macros.\n\      Sample .ncftprc:\n\      #set pager \"less -M\"\n\      \n\      machine wuarchive.wustl.edu\n\          macdef init\n\          cd /pub\n\          get README\n\          dir\n\          (blank line to end macro)"
block|,
literal|"If you want to keep your .netrc's for ftp and ncftp separate, name\n\      ncftp's rc to .ncftprc."
block|,
literal|"Type 'open' by itself to get a list of the sites in your recent-file and\n\      your .ncftprc.  You can then supply '#5' at the prompt, or use 'open #5'\n\      later."
block|,
literal|"Colon-mode is a quick way to get a file from your shell.  Try something\n\      like 'ncftp wuarchive.wustl.edu:/pub/README.'"
block|,
literal|"The open command accepts several flags.  Do a 'help open' for details."
block|,
literal|"Sometimes a directory listing is several screens long and you won't\n\      remember the thing you wanted.  Use the 'predir' command to re-view the\n\      listing.  The program keeps the copy locally, so you won't have to wait\n\      for the remote server to re-send it to you."
block|,
literal|"Use the 'page' (or 'more') command to view a remote file with your pager."
block|,
literal|"ncftp may be keeping detailed information on everything you transfer.\n\      Run the 'version' command and if you see SYSLOG, your actions are being\n\      recorded on the system log."
block|,
literal|"Try the 'redir' command to re-display the last directory listing (ls,\n\      dir, ls -lrt, etc).  'predir' does the same, only with your pager."
block|,
literal|"This program is pronounced Nik-F-T-P.  NCEMRSoft is Nik'-mer-soft."
block|,
ifdef|#
directive|ifdef
name|GETLINE
literal|"NcFTP was compiled with the Getline command-line/history editor! (by\n\      Chris Thewalt<thewalt@ce.berkeley.edu>).  To activate it, use the up\n\      and down arrows to scroll through the history, and/or use EMACS-style\n\      commands to edit the line."
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|READLINE
literal|"NcFTP was compiled with the GNU Readline command-line/history editor!\n\      To activate it, use the up& down arrows to scroll through the history,\n\      and/or use EMACS-style (or maybe VI-style) commands to edit the line."
block|,
endif|#
directive|endif
literal|"You can get the newest version of NcFTP from cse.unl.edu, in the\n\      /pub/mgleason/ncftp directory, AFTER business hours."
block|,
literal|"The type of progress-meter that will be used depends if the remote host\n\      supports the SIZE command, and whether your terminal is capable of ANSI\n\      escape codes."
block|,
literal|"To report a bug, mail your message to mgleason@cse.unl.edu.  Include the\n\      output of the 'version' command in your message.  An easy way to do that\n\      is to compose your message, then do a 'ncftp -H>> msg.'"
block|,
literal|"Don't put a site in your .ncftprc unless you want an 'init' macro.  The \n\      recent-file saves sites with the last directory you were in, unlike \n\      the rc file, while still letting you use sitename abbreviations."
block|,
literal|"You can use World Wide Web style paths instead of colon-mode paths.\n\      For example, if the colon-mode path was 'cse.unl.edu:pub/mgleason/ncftp',\n\      the WWW-style path would be 'ftp://cse.unl.edu/pub/mgleason/ncftp'."
block|,
literal|"Sick and tired of these tips?  Put '#unset tips' in your .ncftprc."
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Not another dinky header, por favor. */
end_comment

begin_define
define|#
directive|define
name|NTIPS
value|((int) (sizeof(tiplist) / sizeof(char *)))
end_define

begin_function_decl
name|void
name|PrintTip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|fromatty
decl_stmt|,
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tips
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_TIPS */
end_comment

begin_function
name|void
name|PrintTip
parameter_list|(
name|void
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|NO_TIPS
name|int
name|cheap_rn
decl_stmt|,
name|i
decl_stmt|,
name|tn
decl_stmt|;
name|string
name|str
decl_stmt|;
if|if
condition|(
name|tips
operator|&&
name|fromatty
condition|)
block|{
name|cheap_rn
operator|=
operator|(
name|int
operator|)
name|getpid
argument_list|()
operator|%
name|NTIPS
expr_stmt|;
if|if
condition|(
name|debug
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"pid: %d;  ntips: %d\n"
argument_list|,
name|getpid
argument_list|()
argument_list|,
name|NTIPS
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|Gets
argument_list|(
literal|"*** Tip# (-1 == all): "
argument_list|,
name|str
argument_list|,
sizeof|sizeof
argument_list|(
name|str
argument_list|)
argument_list|)
expr_stmt|;
name|tn
operator|=
name|atoi
argument_list|(
name|str
argument_list|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|tn
operator|==
operator|-
literal|1
condition|)
name|tn
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tn
operator|<
operator|-
literal|1
condition|)
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NTIPS
condition|;
name|i
operator|++
control|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"Tip: %s\n"
argument_list|,
name|tiplist
index|[
name|i
index|]
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|tn
operator|<
name|NTIPS
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"Tip: %s\n"
argument_list|,
name|tiplist
index|[
name|tn
index|]
argument_list|)
expr_stmt|;
block|}
else|else
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"Tip: %s\n"
argument_list|,
name|tiplist
index|[
name|cheap_rn
index|]
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* NO_TIPS */
block|}
end_function

begin_comment
comment|/* PrintTip */
end_comment

begin_comment
comment|/* tips.c */
end_comment

end_unit

