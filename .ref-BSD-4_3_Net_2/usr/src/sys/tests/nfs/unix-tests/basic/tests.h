begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)tests.h	1.3 90/01/03 NFS Rev 2 Testsuite	*/
end_comment

begin_comment
comment|/*      1.4 Lachman ONC Test Suite  source        */
end_comment

begin_define
define|#
directive|define
name|TESTDIR
value|"/mnt/nfstestdir"
end_define

begin_define
define|#
directive|define
name|DNAME
value|"dir."
end_define

begin_define
define|#
directive|define
name|FNAME
value|"file."
end_define

begin_define
define|#
directive|define
name|DCOUNT
value|10
end_define

begin_define
define|#
directive|define
name|DDIRS
value|2
end_define

begin_define
define|#
directive|define
name|DLEVS
value|5
end_define

begin_define
define|#
directive|define
name|DFILS
value|5
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Myname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name I was invoked with (for error msgs */
end_comment

end_unit

