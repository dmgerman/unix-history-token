begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  VERSION.H -- system version definition file. ** **	NOTICE: **		Version numbers stored in files are SCCS id's **		and may not correspond to the external distribution **		version number.  The distribution number applies to **		the entire system and not to any particular file. **		This file defines a "release" number, used for **		creating file names.  The entire system version **		number (including mod number) is defined by **		conf/version.c. ** **	Version: **		@(#)version.h	7.1	2/5/81 */
end_comment

begin_comment
comment|/* **	VERSION is the version number of this incarnation of INGRES **		for purposes of creating file names. **	DBVERCODE is the code for this database version stored in **		the admin file. **	PATHEXT is an extension for the path as derived from the **		"ingres" entry in the password file to determine **		the "Pathname" variable.  If it is not defined, **		no extension is made. */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"7"
end_define

begin_comment
comment|/* version number */
end_comment

begin_define
define|#
directive|define
name|DBVERCODE
value|1
end_define

begin_comment
comment|/* database version code */
end_comment

begin_comment
comment|/* # define	PATHEXT		"/x"		/* the root path extension */
end_comment

end_unit

