begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gp.h */
end_comment

begin_comment
comment|/* Interface to platform-specific routines for Ghostscript */
end_comment

begin_comment
comment|/*  * This file defines ***ALL*** the routines that are Ghostscript- and  * platform-specific.  The routines are implemented in a gp_*.c file  * specific to each platform.  We try very hard to keep this list short!  */
end_comment

begin_comment
comment|/* ------ Initialization/termination ------ */
end_comment

begin_comment
comment|/*  * This routine is called early in the Ghostscript initialization.  * It should do as little as possible.  In particular, it should not  * do things like open display connections: that is the responsibility  * of the display device driver.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_init
argument_list|(
name|P0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This routine is called just before Ghostscript exits (normally or  * abnormally).  It too should do as little as possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_exit
argument_list|(
name|P0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Date and time ------ */
end_comment

begin_comment
comment|/*  * Read the current date (in days since Jan. 1, 1980) into pdt[0],  * and time (in milliseconds since midnight) into pdt[1].  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_get_clock
argument_list|(
name|P1
argument_list|(
name|long
operator|*
name|pdt
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Screen management ------ */
end_comment

begin_comment
comment|/*  * These routines are only relevant in a single-window environment  * such as a PC; on platforms with window systems, the 'make current'  * routines do nothing.  */
end_comment

begin_struct_decl
struct_decl|struct
name|gx_device_s
struct_decl|;
end_struct_decl

begin_comment
comment|/* Write a string to the console. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_console_puts
argument_list|(
name|P2
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make the console current on the screen. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gp_make_console_current
argument_list|(
name|P1
argument_list|(
expr|struct
name|gx_device_s
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make the graphics current on the screen. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gp_make_graphics_current
argument_list|(
name|P1
argument_list|(
expr|struct
name|gx_device_s
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Printer accessing ------ */
end_comment

begin_comment
comment|/*  * Open a connection to a printer.  A null file name means use the  * standard printer connected to the machine, if any.  * If possible, support "|command" for opening an output pipe.  * Return NULL if the connection could not be opened.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|gp_open_printer
argument_list|(
name|P1
argument_list|(
name|char
operator|*
name|fname
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Close the connection to the printer. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_close_printer
argument_list|(
name|P2
argument_list|(
name|FILE
operator|*
name|pfile
argument_list|,
specifier|const
name|char
operator|*
name|fname
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ File names ------ */
end_comment

begin_comment
comment|/* Define the character used for separating file names in a list. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|gp_file_name_list_separator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the default scratch file name prefix. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|gp_scratch_file_name_prefix
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define whether case is insignificant in file names. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|gp_file_names_ignore_case
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create and open a scratch file with a given name prefix. */
end_comment

begin_comment
comment|/* Write the actual file name at fname. */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|gp_open_scratch_file
argument_list|(
name|P3
argument_list|(
specifier|const
name|char
operator|*
name|prefix
argument_list|,
name|char
operator|*
name|fname
argument_list|,
specifier|const
name|char
operator|*
name|mode
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Answer whether a file name contains a directory/device specification, */
end_comment

begin_comment
comment|/* i.e. is absolute (not directory- or device-relative). */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gp_file_name_is_absolute
argument_list|(
name|P2
argument_list|(
argument|const char *fname
argument_list|,
argument|uint len
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Answer the string to be used for combining a directory/device prefix */
end_comment

begin_comment
comment|/* with a base file name.  The file name is known to not be absolute. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|gp_file_name_concat_string
argument_list|(
name|P4
argument_list|(
argument|const char *prefix
argument_list|,
argument|uint plen
argument_list|,
argument|const char *fname
argument_list|,
argument|uint len
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ File operations ------ */
end_comment

begin_comment
comment|/* If the file given by fname exists, fill in its status and return 1; */
end_comment

begin_comment
comment|/* otherwise return 0. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|file_status_s
block|{
name|long
name|size_pages
decl_stmt|;
name|long
name|size_bytes
decl_stmt|;
name|long
name|time_referenced
decl_stmt|;
name|long
name|time_created
decl_stmt|;
block|}
name|file_status
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|gp_file_status
argument_list|(
name|P2
argument_list|(
specifier|const
name|char
operator|*
name|fname
argument_list|,
name|file_status
operator|*
name|pstatus
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ File enumeration ------ */
end_comment

begin_struct_decl
struct_decl|struct
name|file_enum_s
struct_decl|;
end_struct_decl

begin_comment
comment|/* opaque to client, defined by implementor */
end_comment

begin_typedef
typedef|typedef
name|struct
name|file_enum_s
name|file_enum
typedef|;
end_typedef

begin_comment
comment|/*  * Begin an enumeration.  pat is a C string that may contain *s or ?s.  * The implementor should copy the string to a safe place.  * If the operating system doesn't support correct, arbitrarily placed  * *s and ?s, the implementation should modify the string so that it  * will return a conservative superset of the request.  E.g., if the OS  * doesn't implement ? (single-character wild card), any consecutive  * string of ?s should be interpreted as *.  Note that \ can appear in  * the pattern also, as a quoting character.  */
end_comment

begin_decl_stmt
specifier|extern
name|file_enum
modifier|*
name|gp_enumerate_files_init
argument_list|(
name|P4
argument_list|(
argument|const char *pat
argument_list|,
argument|uint patlen
argument_list|,
argument|proc_alloc_t palloc
argument_list|,
argument|proc_free_t pfree
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return the next file name in the enumeration.  The client passes in  * a scratch string and a max length.  If the name of the next file fits,  * the procedure returns the length.  If it doesn't fit, the procedure  * returns max length +1.  If there are no more files, the procedure  * returns -1.  */
end_comment

begin_decl_stmt
specifier|extern
name|uint
name|gp_enumerate_files_next
argument_list|(
name|P3
argument_list|(
argument|file_enum *pfen
argument_list|,
argument|char *ptr
argument_list|,
argument|uint maxlen
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Clean up a file enumeration.  This is only called to abandon  * an enumeration partway through: ...next should do it if there are  * no more files to enumerate.  This should deallocate the file_enum  * structure and any subsidiary structures, strings, buffers, etc.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_enumerate_files_close
argument_list|(
name|P1
argument_list|(
name|file_enum
operator|*
name|pfen
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

