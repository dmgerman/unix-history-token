begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* this file contains the site dependent items for the ipq, iprm, ipch  * and impv routines.  *  * history   *  * created by Ted Bentley  * University of Alberta  * February 1984  * Color revisions: Martin Dubetz January 1985  */
end_comment

begin_comment
comment|/* $Header: site.h,v 10.3 86/02/01 16:00:33 tony Rel $ */
end_comment

begin_define
define|#
directive|define
name|REMOTE_HOST
value|"alberta"
end_define

begin_comment
comment|/* The host where the spool files are */
end_comment

begin_define
define|#
directive|define
name|P_SERV
value|"impvserv"
end_define

begin_comment
comment|/* The name of the server on that host */
end_comment

begin_define
define|#
directive|define
name|SCREEN_FILE
value|"/usr/tmp/impvXXXXXX"
end_define

begin_comment
comment|/* the disk file for screen images */
end_comment

begin_define
define|#
directive|define
name|SAVE_PAGES
value|5
end_define

begin_comment
comment|/* the number of screen images to save */
end_comment

begin_define
define|#
directive|define
name|NOSPOOL
end_define

begin_comment
comment|/* no spool file, local previewing only*/
end_comment

begin_comment
comment|/*  #define XWIND		/* DO NOT TURN ON, MAKEFILE DOES IT */
end_comment

begin_comment
comment|/*for VAXSTATION */
end_comment

begin_comment
comment|/*  #define IMAGEN300		/* for IMAGEN 300 dpi*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XWIND
end_ifndef

begin_define
define|#
directive|define
name|COLOR
end_define

begin_comment
comment|/* include the color slide option */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IMAGEN300
end_ifdef

begin_define
define|#
directive|define
name|SIZED
end_define

begin_define
define|#
directive|define
name|MAXx
value|2550
end_define

begin_comment
comment|/* maximum number of dots imagen 300 page */
end_comment

begin_define
define|#
directive|define
name|MAXy
value|3300
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUN120
end_ifdef

begin_define
define|#
directive|define
name|LEFTE
value|126
end_define

begin_comment
comment|/* left edge of pscreen to start at */
end_comment

begin_else
else|#
directive|else
else|SUN120
end_else

begin_define
define|#
directive|define
name|LEFTE
value|62
end_define

begin_comment
comment|/* left edge of pscreen to start at */
end_comment

begin_endif
endif|#
directive|endif
endif|SUN120
end_endif

begin_endif
endif|#
directive|endif
endif|IMAGEN300
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZED
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IMAGEN480
end_ifdef

begin_define
define|#
directive|define
name|MAXx
value|4080
end_define

begin_comment
comment|/* maximum number of dots imagen 480 page */
end_comment

begin_define
define|#
directive|define
name|MAXy
value|5280
end_define

begin_define
define|#
directive|define
name|LEFTE
value|0
end_define

begin_comment
comment|/* left edge of pscreen to start at */
end_comment

begin_else
else|#
directive|else
else|IMAGEN480
end_else

begin_define
define|#
directive|define
name|MAXx
value|2040
end_define

begin_comment
comment|/* maximum number of dots imagen 240 page */
end_comment

begin_define
define|#
directive|define
name|MAXy
value|2640
end_define

begin_define
define|#
directive|define
name|LEFTE
value|0
end_define

begin_comment
comment|/* left edge of pscreen to start at */
end_comment

begin_endif
endif|#
directive|endif
endif|IMAGEN480
end_endif

begin_endif
endif|#
directive|endif
endif|SIZED
end_endif

begin_comment
comment|/* these likely won't change */
end_comment

begin_define
define|#
directive|define
name|SMAXx
value|(MAXx / 2)
end_define

begin_comment
comment|/* number of dots on a screen page */
end_comment

begin_define
define|#
directive|define
name|SMAXy
value|(MAXy / 2)
end_define

begin_comment
comment|/* calculate the screen size in bytes 2::1 compression */
end_comment

begin_define
define|#
directive|define
name|SCREENSIZE
value|(((SMAXx + 7) / 8) * SMAXy )
end_define

end_unit

