begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uutime.h    Header file for UUCP time routines.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o AIRS, P.O. Box 520, Waltham, MA 02254.     $Log: uutime.h,v $    Revision 1.2  1992/03/09  05:08:16  ian    Added status for wrong time to call, not used if system can't be called     Revision 1.1  1992/03/07  02:56:30  ian    Initial revision      */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UUTIME_H
end_ifndef

begin_define
define|#
directive|define
name|UUTIME_H
end_define

begin_escape
end_escape

begin_comment
comment|/* Timetables are kept in a array of pairs of strings.  */
end_comment

begin_struct
struct|struct
name|stimetable
block|{
comment|/* Name of timetable.  */
specifier|const
name|char
modifier|*
name|zname
decl_stmt|;
comment|/* Time string.  */
specifier|const
name|char
modifier|*
name|ztime
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|cTtable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stimetable
modifier|*
name|pasTtable
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* A time string is parsed into a list of the following structures.    Each element of the list represents a span of time.  The time    string matches any time that is one of the spans.  The time may    only depend on the day of the week, not on the day of the month or    of the year.  Also, the time is specified only down to the minute,    not down to the second or below.     The starting and ending time are expressed in minutes since the    beginning of the week, which is considered to be 12 midnight on    Sunday.  Thus 60 is 1 am on Sunday, 1440 (== 60 * 24) is 12    midnight on Monday, and the largest possible value is 10080 (== 60    * 24 * 7) which is 12 midnight on the following Sunday.     Each span of time has a value associated with it.  This is the    lowest grade or the largest file size that may be transferred    during the span.  When we add a new time span that overlaps with an    existing one, we use the span with the higher grade or the smaller    file size.  Thus specifying ``call-timegrade z Any'' and    ``call-timegrade Z Mo'' means that only grade Z or higher may be    sent on Monday, since Z is the higer grade of the overlapping    spans.  After determining which grade or file size to use, we    eliminate all overlaps.     Each span also has a retry time associated with it.  This permits    different retry times to be used at different times of day.  */
end_comment

begin_struct
struct|struct
name|sspan
block|{
comment|/* Next time span in this list.  */
name|struct
name|sspan
modifier|*
name|qnext
decl_stmt|;
comment|/* Value for this span (lowest grade or largest file that may be      transferred at this time).  */
name|long
name|ival
decl_stmt|;
comment|/* Starting minute.  */
name|int
name|istart
decl_stmt|;
comment|/* Ending minute.  */
name|int
name|iend
decl_stmt|;
comment|/* Retry time.  */
name|int
name|cretry
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Time functions.  */
end_comment

begin_comment
comment|/* Initialize the array of timetables.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uinittimetables
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a new timetable entry.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uaddtimetable
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zname
operator|,
specifier|const
name|char
operator|*
name|ztime
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a timegrade string into a time span.  A timegrade string is a    sequence of strings separated by a single space.  The first    character of each string is a grade.  The second character begins a    time string.  The time string may end in a semicolon followed by a    retry time.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sspan
modifier|*
name|qtimegrade_parse
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|ztimegrade
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a timesize string into a time span.  A timespan string is a    sequence of pairs of strings, all separated by a single space.  The    first string in each pair is a numeric size.  The second string is    a time string.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sspan
modifier|*
name|qtimesize_parse
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|ztimesize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See if the current time matches a time span.  If not, return FALSE.    Otherwise, return TRUE and set *pival and *pcretry to the values    from the matching element of the span.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|ftimespan_match
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|sspan
operator|*
operator|,
name|long
operator|*
name|pival
operator|,
name|int
operator|*
name|pcretry
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a time span returned by either qtparse_timesize or    qtparse_timegrade.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|utimespan_free
name|P
argument_list|(
operator|(
expr|struct
name|sspan
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine the grade of work permitted at the current time, given a    timegrade string.  This parses the timegrade string, locates the    entry corresponding to the current time, and returns the associated    grade.  If no time in the timegrade string matches, this returns    '\0'.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|btimegrade
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|ztimegrade
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine the maximum size that may be transferred at the current    time, given a timesize string.  This parses the timesize string,    locates the entry corresponding to the current time, and returns    the associated size.  If no time in the timesize string matches,    this returns -1.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|cmax_size_now
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|ztimesize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine the maximum size that may ever be transferred, given a    timesize string.  If there are any time gaps larger than 1 hour not    described by the timesize string, this returns -1.  Otherwise it    returns the largest size that may be transferred at some time.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|cmax_size_ever
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|ztimesize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (UUTIME_H) */
end_comment

end_unit

