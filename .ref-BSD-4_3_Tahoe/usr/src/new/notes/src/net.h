begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|RCSIDENT
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAINLINE
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|zznetid
index|[]
init|=
literal|"$Header: net.h,v 1.7 85/01/18 15:44:16 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(RCSIDENT)&& defined(MAINLINE)
end_endif

begin_comment
comment|/*  *	This file describes the format of the net.how file in the  *	notesfile utility directory. The file is designed to  *	allow the reconfiguration of the network software to follow  *	non-uucp links. The format of a line in the file is:  *  *	system:direction:protocol number::printf control string  *  *	the direction field is contains an x or r, for transmit and  *	reply. The transmit field is used for sending notes to the  *	remote site. The reply lines are used for tickling the   *	remote system into sending notes back.  *	The third and fourth fields are reserved for future expansion.  *	The printf control string contains 2 %s arguements.  *	The first one is the name of the notesfile being sent,  *	the second is for the local system name.  *	The receive string is similar.  *  *	The default control string is:  *		"uux -r -n - tosite!nfrcv %s %s"  *	for transmission, and for replies it is:  *		"uux  -z farsite!nfxmit %s -d%s"  *  *	In the default case, the tosite/farsite names are filled in.  *  *	the "-r" flag to uux means don't try to start a uucico.  *  *	A sample of our file:  *  *	uicsovax:x:::uux - uicsovax\!/mnt/dcs/essick/.commands/nfrcv %s %s  *	uicsovax:r:::uux uicsovax\!/mnt/dcs/essick/.commands/nfxmit %s -d%s  *  *	Ray Essick	Aprli 23, 1982  */
end_comment

begin_define
define|#
directive|define
name|NFXMIT
value|"nfxmit"
end_define

begin_comment
comment|/* path to nf xmit */
end_comment

begin_define
define|#
directive|define
name|NFRCV
value|"nfrcv"
end_define

begin_comment
comment|/* path to reciever */
end_comment

begin_define
define|#
directive|define
name|DFLTXMIT
value|"uux -r -n - %s\!%s %s %s< %s"
end_define

begin_comment
comment|/* default xmit */
end_comment

begin_define
define|#
directive|define
name|DFLTRPLY
value|"uux -n %s\!%s %s -d%s"
end_define

begin_comment
comment|/* default reply */
end_comment

begin_define
define|#
directive|define
name|NETHOW
value|"net.how"
end_define

begin_comment
comment|/* file containing net links */
end_comment

begin_define
define|#
directive|define
name|ALIASES
value|"net.aliases"
end_define

begin_comment
comment|/* alias directory */
end_comment

begin_comment
comment|/*  *	bits in "sendhim" parameter to nfsend().  */
end_comment

begin_define
define|#
directive|define
name|SENDNEWS
value|001
end_define

begin_comment
comment|/* stuff from news */
end_comment

begin_define
define|#
directive|define
name|SENDHIS
value|002
end_define

begin_comment
comment|/* stuff he's seen */
end_comment

end_unit

