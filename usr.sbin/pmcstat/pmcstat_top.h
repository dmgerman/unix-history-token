begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Fabien Thomas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMCSTAT_TOP_H_
end_ifndef

begin_define
define|#
directive|define
name|_PMCSTAT_TOP_H_
end_define

begin_comment
comment|/* Return the ncurses attributes for the given value. */
end_comment

begin_define
define|#
directive|define
name|PMCSTAT_ATTRPERCENT
parameter_list|(
name|b
parameter_list|)
define|\
value|((b)> 10.0 ? (args.pa_topcolor ? COLOR_PAIR(1) : A_BOLD) :	\     ((b)>  5.0 ? (args.pa_topcolor ? COLOR_PAIR(2) : 0) : 	\     ((b)>  2.5 ? (args.pa_topcolor ? COLOR_PAIR(3) : 0) : 0)))
end_define

begin_comment
comment|/* Print to the default ncurse windows if on a terminal or to the file. */
end_comment

begin_define
define|#
directive|define
name|PMCSTAT_PRINTW
parameter_list|(
modifier|...
parameter_list|)
value|do {			\ 	if (args.pa_toptty)				\ 		printw(__VA_ARGS__);			\ 	else						\ 		fprintf(args.pa_printfile, __VA_ARGS__);\ } while (0)
end_define

begin_comment
comment|/* If ncurses mode active set attributes. */
end_comment

begin_define
define|#
directive|define
name|PMCSTAT_ATTRON
parameter_list|(
name|b
parameter_list|)
value|do {				\ 	if (args.pa_toptty)				\ 		attron(b);				\ } while (0)
end_define

begin_comment
comment|/* If ncurses mode active unset attributes. */
end_comment

begin_define
define|#
directive|define
name|PMCSTAT_ATTROFF
parameter_list|(
name|b
parameter_list|)
value|do {				\ 	if (args.pa_toptty)				\ 		attroff(b);				\ } while (0)
end_define

begin_comment
comment|/* Erase screen and set cursor to top left. */
end_comment

begin_define
define|#
directive|define
name|PMCSTAT_PRINTBEGIN
parameter_list|()
value|do {			\ 	if (args.pa_toptty)				\ 		clear();				\ } while (0)
end_define

begin_comment
comment|/* Flush buffer to backend. */
end_comment

begin_define
define|#
directive|define
name|PMCSTAT_PRINTEND
parameter_list|()
value|do {				\ 	if (!args.pa_toptty) {				\ 		PMCSTAT_PRINTW("---\n");		\ 		fflush(args.pa_printfile);		\ 	} else						\ 		refresh();				\ } while (0)
end_define

begin_comment
comment|/* Function prototypes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PMCSTAT_TOP_H_ */
end_comment

end_unit

