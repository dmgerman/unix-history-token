begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software_Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* sup.h -- declarations for sup, supnamesrv, supfilesrv  *  * VERSION NUMBER for any program is given by:  a.b (c)  * where	a = PROTOVERSION	is the protocol version #  *		b = PGMVERSION		is program # within protocol  *		c = scmversion		is communication module version  *			(i.e. operating system for which scm is configured)  **********************************************************************  * HISTORY  * 13-Sep-92  Mary Thompson (mrt) at Carnegie-Mellon University  *	Changed name of DEFDIR from /usr/cs to /usr.  *  * 7-July-93  Nate Williams at Montana State University  *	Modified SUP to use gzip based compression when sending files  *	across the network to save BandWidth  *  * $Log: sup.h,v $  * Revision 1.1.1.1  1993/08/21  00:46:34  jkh  * Current sup with compression support.  *  * Revision 1.1.1.1  1993/05/21  14:52:18  cgd  * initial import of CMU's SUP to NetBSD  *  * Revision 1.10  92/08/11  12:06:42  mrt  * 	Added definition for DEBUGFPORTNUM, the debugging port number.  * 	Changed so that last and when file names could include  * 	the relase name if any.  * 	[92/07/23            mrt]  *   * Revision 1.9  91/04/29  14:39:03  mja  * 	Reduce MAXCHILDREN from 8 to 3.  *   * Revision 1.8  89/08/23  14:55:30  gm0w  * 	Moved coll.dir from supservers to supfiles.  * 	[89/08/23            gm0w]  *   * 18-Mar-88  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added host=<hostfile> support to releases file.  *  * 27-Dec-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added crosspatch support.  Removed nameserver support.  *  * 27-Jun-87  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added TREELIST and other changes for "release" support.  *  * 25-May-87  Doug Philips (dwp) at Carnegie-Mellon University  *	Version 6 of the network protocol, better support to reflect errors  *	back to server logfile.  *  * 21-May-87  Chriss Stephens (chriss) at Carnegie Mellon University  *	Merged divergent CS and EE versions.  *  * 19-Sep-86  Mike Accetta (mja) at Carnegie-Mellon University  *	Added FILESUPTDEFAULT definition.  *  * 07-Jun-86  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Removed FILESRVBUSYWAIT.  Now uses exponential backoff.  *  * 30-May-86  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added numeric port numbers to use when port names are not in the  *	host table.  *  * 04-Jan-86  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Update protocol version to 5 for name server protocol change to  *	allow multiple repositories per collection.  Added FILESRVBUSYWAIT  *	of 5 minutes.  Added FILELOCK file to indicate collections that  *	should be exclusively locked when upgraded.  *  * 22-Sep-85  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Merged 4.1 and 4.2 versions together.  *  * 04-Jun-85  Steven Shafer (sas) at Carnegie-Mellon University  *	Created for 4.2 BSD.  *  **********************************************************************  */
end_comment

begin_comment
comment|/* PGMVERSION is defined separately in each program */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|scmversion
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string version of scm */
end_comment

begin_define
define|#
directive|define
name|PROTOVERSION
value|8
end_define

begin_comment
comment|/* version of network protocol */
end_comment

begin_define
define|#
directive|define
name|SCANVERSION
value|2
end_define

begin_comment
comment|/* version of scan file format */
end_comment

begin_comment
comment|/* TCP servers for name server and file server */
end_comment

begin_define
define|#
directive|define
name|FILEPORT
value|"supfilesrv"
end_define

begin_define
define|#
directive|define
name|FILEPORTNUM
value|871
end_define

begin_define
define|#
directive|define
name|DEBUGFPORT
value|"supfiledbg"
end_define

begin_define
define|#
directive|define
name|DEBUGFPORTNUM
value|1127
end_define

begin_comment
comment|/* Data files used in scan.c */
end_comment

begin_define
define|#
directive|define
name|FILELIST
value|"sup/%s/%s"
end_define

begin_define
define|#
directive|define
name|FILESCAN
value|"sup/%s/%s"
end_define

begin_define
define|#
directive|define
name|FILEHOST
value|"sup/%s/%s"
end_define

begin_define
define|#
directive|define
name|FILELISTDEF
value|"list"
end_define

begin_define
define|#
directive|define
name|FILESCANDEF
value|"scan"
end_define

begin_define
define|#
directive|define
name|FILEHOSTDEF
value|"host"
end_define

begin_define
define|#
directive|define
name|DEFRELEASE
value|"default"
end_define

begin_comment
comment|/* Data files used in sup.c */
end_comment

begin_define
define|#
directive|define
name|FILEBASEDEFAULT
value|"/usr/%s"
end_define

begin_comment
comment|/* also supfilesrv and supscan */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EE_XXX
end_ifdef

begin_define
define|#
directive|define
name|FILESUPDEFAULT
value|"%s/supfiles/coll.list"
end_define

begin_define
define|#
directive|define
name|FILESUPTDEFAULT
value|"%s/supfiles/coll.what"
end_define

begin_define
define|#
directive|define
name|FILEHOSTS
value|"%s/supfiles/coll.host"
end_define

begin_else
else|#
directive|else
else|EE_XXX
end_else

begin_define
define|#
directive|define
name|FILESUPDEFAULT
value|"%s/lib/supfiles/coll.list"
end_define

begin_define
define|#
directive|define
name|FILESUPTDEFAULT
value|"%s/lib/supfiles/coll.what"
end_define

begin_define
define|#
directive|define
name|FILEHOSTS
value|"%s/lib/supfiles/coll.host"
end_define

begin_endif
endif|#
directive|endif
endif|EE_XXX
end_endif

begin_define
define|#
directive|define
name|FILEBKDIR
value|"%s/BACKUP"
end_define

begin_define
define|#
directive|define
name|FILEBACKUP
value|"%s/BACKUP/%s"
end_define

begin_define
define|#
directive|define
name|FILELAST
value|"sup/%s/last%s"
end_define

begin_define
define|#
directive|define
name|FILELASTTEMP
value|"sup/%s/last.temp"
end_define

begin_define
define|#
directive|define
name|FILELOCK
value|"sup/%s/lock"
end_define

begin_comment
comment|/* also supfilesrv */
end_comment

begin_define
define|#
directive|define
name|FILEREFUSE
value|"sup/%s/refuse"
end_define

begin_define
define|#
directive|define
name|FILEWHEN
value|"sup/%s/when%s"
end_define

begin_comment
comment|/* Data files used in supfilesrv.c */
end_comment

begin_define
define|#
directive|define
name|FILEXPATCH
value|"%s/sup/xpatch.host"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EE_XXX
end_ifdef

begin_define
define|#
directive|define
name|FILEDIRS
value|"%s/supfiles/coll.dir"
end_define

begin_comment
comment|/* also supscan */
end_comment

begin_else
else|#
directive|else
else|EE_XXX
end_else

begin_define
define|#
directive|define
name|FILEDIRS
value|"%s/lib/supfiles/coll.dir"
end_define

begin_comment
comment|/* also supscan */
end_comment

begin_endif
endif|#
directive|endif
endif|EE_XXX
end_endif

begin_define
define|#
directive|define
name|FILECRYPT
value|"sup/%s/crypt"
end_define

begin_define
define|#
directive|define
name|FILELOGFILE
value|"sup/%s/logfile"
end_define

begin_define
define|#
directive|define
name|FILEPREFIX
value|"sup/%s/prefix"
end_define

begin_comment
comment|/* also supscan */
end_comment

begin_define
define|#
directive|define
name|FILERELEASES
value|"sup/%s/releases"
end_define

begin_comment
comment|/* also supscan */
end_comment

begin_comment
comment|/* String length */
end_comment

begin_define
define|#
directive|define
name|STRINGLENGTH
value|2000
end_define

begin_comment
comment|/* Password transmission encryption key */
end_comment

begin_define
define|#
directive|define
name|PSWDCRYPT
value|"SuperMan"
end_define

begin_comment
comment|/* Test string for encryption */
end_comment

begin_define
define|#
directive|define
name|CRYPTTEST
value|"Hello there, Sailor Boy!"
end_define

begin_comment
comment|/* Default directory for system sup information */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|EE_XXX
end_ifdef

begin_define
define|#
directive|define
name|DEFDIR
value|"/etc"
end_define

begin_else
else|#
directive|else
else|EE_XXX
end_else

begin_define
define|#
directive|define
name|DEFDIR
value|"/usr"
end_define

begin_endif
endif|#
directive|endif
endif|EE_XXX
end_endif

begin_endif
endif|#
directive|endif
endif|DEFDIR
end_endif

begin_comment
comment|/* Default login account for file server */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFUSER
end_ifndef

begin_define
define|#
directive|define
name|DEFUSER
value|"anon"
end_define

begin_endif
endif|#
directive|endif
endif|DEFUSER
end_endif

begin_comment
comment|/* subroutine return codes */
end_comment

begin_define
define|#
directive|define
name|SCMOK
value|(1)
end_define

begin_comment
comment|/* routine performed correctly */
end_comment

begin_define
define|#
directive|define
name|SCMEOF
value|(0)
end_define

begin_comment
comment|/* read EOF on network connection */
end_comment

begin_define
define|#
directive|define
name|SCMERR
value|(-1)
end_define

begin_comment
comment|/* error occurred during routine */
end_comment

begin_comment
comment|/* data structure for describing a file being upgraded */
end_comment

begin_struct
struct|struct
name|treestruct
block|{
comment|/* fields for file information */
name|char
modifier|*
name|Tname
decl_stmt|;
comment|/* path component name */
name|int
name|Tflags
decl_stmt|;
comment|/* flags of file */
name|int
name|Tmode
decl_stmt|;
comment|/* st_mode of file */
name|char
modifier|*
name|Tuser
decl_stmt|;
comment|/* owner of file */
name|int
name|Tuid
decl_stmt|;
comment|/* owner id of file */
name|char
modifier|*
name|Tgroup
decl_stmt|;
comment|/* group of file */
name|int
name|Tgid
decl_stmt|;
comment|/* group id of file */
name|int
name|Tctime
decl_stmt|;
comment|/* inode modification time */
name|int
name|Tmtime
decl_stmt|;
comment|/* data modification time */
name|struct
name|treestruct
modifier|*
name|Tlink
decl_stmt|;
comment|/* tree of link names */
name|struct
name|treestruct
modifier|*
name|Texec
decl_stmt|;
comment|/* tree of execute commands */
comment|/* fields for sibling AVL tree */
name|int
name|Tbf
decl_stmt|;
comment|/* balance factor */
name|struct
name|treestruct
modifier|*
name|Tlo
decl_stmt|,
modifier|*
name|Thi
decl_stmt|;
comment|/* ordered sibling tree */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|treestruct
name|TREE
typedef|;
end_typedef

begin_comment
comment|/* data structure to represent a list of trees to upgrade */
end_comment

begin_struct
struct|struct
name|tliststruct
block|{
name|struct
name|tliststruct
modifier|*
name|TLnext
decl_stmt|;
comment|/* next entry in tree list */
comment|/* fields for tree information */
name|char
modifier|*
name|TLname
decl_stmt|;
comment|/* release name for tree */
name|char
modifier|*
name|TLprefix
decl_stmt|;
comment|/* prefix of tree */
name|char
modifier|*
name|TLlist
decl_stmt|;
comment|/* name of list file */
name|char
modifier|*
name|TLscan
decl_stmt|;
comment|/* name of scan file */
name|char
modifier|*
name|TLhost
decl_stmt|;
comment|/* name of host file */
name|TREE
modifier|*
name|TLtree
decl_stmt|;
comment|/* tree of files to upgrade */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tliststruct
name|TREELIST
typedef|;
end_typedef

begin_comment
comment|/* bitfield not defined in stat.h */
end_comment

begin_define
define|#
directive|define
name|S_IMODE
value|07777
end_define

begin_comment
comment|/* part of st_mode that chmod sets */
end_comment

begin_comment
comment|/* flag bits for files */
end_comment

begin_define
define|#
directive|define
name|FNEW
value|01
end_define

begin_comment
comment|/* ctime of file has changed */
end_comment

begin_define
define|#
directive|define
name|FBACKUP
value|02
end_define

begin_comment
comment|/* backup of file is allowed */
end_comment

begin_define
define|#
directive|define
name|FNOACCT
value|04
end_define

begin_comment
comment|/* don't set file information */
end_comment

begin_define
define|#
directive|define
name|FUPDATE
value|010
end_define

begin_comment
comment|/* only set file information */
end_comment

begin_define
define|#
directive|define
name|FNEEDED
value|0100000
end_define

begin_comment
comment|/* file needed for upgrade */
end_comment

begin_comment
comment|/* version 3 compatability */
end_comment

begin_define
define|#
directive|define
name|FCOMPAT
value|0010000
end_define

begin_comment
comment|/* Added to detect execute commands to send */
end_comment

begin_comment
comment|/* message types now obsolete */
end_comment

begin_define
define|#
directive|define
name|MSGFEXECQ
value|(115)
end_define

begin_define
define|#
directive|define
name|MSGFEXECNAMES
value|(116)
end_define

begin_comment
comment|/* flag bits for files in list of all files */
end_comment

begin_define
define|#
directive|define
name|ALLNEW
value|01
end_define

begin_define
define|#
directive|define
name|ALLBACKUP
value|02
end_define

begin_define
define|#
directive|define
name|ALLEND
value|04
end_define

begin_define
define|#
directive|define
name|ALLDIR
value|010
end_define

begin_define
define|#
directive|define
name|ALLNOACCT
value|020
end_define

begin_define
define|#
directive|define
name|ALLSLINK
value|0100
end_define

begin_comment
comment|/* flag bits for file mode word */
end_comment

begin_define
define|#
directive|define
name|MODELINK
value|010000
end_define

begin_define
define|#
directive|define
name|MODEDIR
value|040000
end_define

begin_define
define|#
directive|define
name|MODESYM
value|0100000
end_define

begin_define
define|#
directive|define
name|MODENOACCT
value|0200000
end_define

begin_define
define|#
directive|define
name|MODEUPDATE
value|01000000
end_define

begin_comment
comment|/* blocking factor for filenames in list of all file names */
end_comment

begin_define
define|#
directive|define
name|BLOCKALL
value|32
end_define

begin_comment
comment|/* end version 3 compatability */
end_comment

begin_define
define|#
directive|define
name|MAXCHILDREN
value|3
end_define

begin_comment
comment|/* maximum number of children allowed 					   to sup at the same time */
end_comment

begin_comment
comment|/* scm and stree external declarations */
end_comment

begin_function_decl
name|char
modifier|*
name|remotehost
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|TREE
modifier|*
name|Tinsert
argument_list|()
decl_stmt|,
modifier|*
name|Tsearch
argument_list|()
decl_stmt|,
modifier|*
name|Tlookup
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

