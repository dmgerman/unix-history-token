begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|version_string
init|=
literal|"@(#)GNU Awk 3.0"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.02		fixed /= += *= etc to return the new Left Hand Side instead 		of the Right Hand Side */
end_comment

begin_comment
comment|/* 1.03		Fixed split() to treat strings of space and tab as FS if 		the split char is ' '.  		Added -v option to print version number  		 		Fixed bug that caused rounding when printing large numbers  */
end_comment

begin_comment
comment|/* 2.00beta	Incorporated the functionality of the "new" awk as described 		the book (reference not handy).  Extensively tested, but no  		doubt still buggy.  Badly needs tuning and cleanup, in 		particular in memory management which is currently almost 		non-existent. */
end_comment

begin_comment
comment|/* 2.01		JF:  Modified to compile under GCC, and fixed a few 		bugs while I was at it.  I hope I didn't add any more. 		I modified parse.y to reduce the number of reduce/reduce 		conflicts.  There are still a few left. */
end_comment

begin_comment
comment|/* 2.02		Fixed JF's bugs; improved memory management, still needs 		lots of work. */
end_comment

begin_comment
comment|/* 2.10		Major grammar rework and lots of bug fixes from David. 		Major changes for performance enhancements from David. 		A number of minor bug fixes and new features from Arnold. 		Changes for MSDOS from Conrad Kwok and Scott Garfinkle. 		The gawk.texinfo and info files included! */
end_comment

begin_comment
comment|/* 2.11		Bug fix release to 2.10.  Lots of changes for portability, 		speed, and configurability.  */
end_comment

begin_comment
comment|/* 2.12		Lots of changes for portability, speed, and configurability. 		Several bugs fixed.  POSIX compliance.  Removal of last set 		of hard-wired limits.  Atari and VMS ports added. */
end_comment

begin_comment
comment|/* 2.13		Public release of 2.12 */
end_comment

begin_comment
comment|/* 2.14		Mostly bug fixes. */
end_comment

begin_comment
comment|/* 2.15		Bug fixes plus intermixing of command-line source and files, 		GNU long options, ARGIND, ERRNO and Plan 9 style /dev/ files. 		`delete array'. OS/2 port added. */
end_comment

begin_comment
comment|/* 3.0		RS as regexp, RT variable, FS = "", fflush builtin, posix 		regexps, IGNORECASE applies to all comparison, autoconf, source 		code cleanup. See the NEWS file. */
end_comment

end_unit

