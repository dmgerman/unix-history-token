begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)externs.c	5.3 (Berkeley) 6/18/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"trek.h"
end_include

begin_comment
comment|/* **	global variable definitions */
end_comment

begin_decl_stmt
name|struct
name|device
name|Device
index|[
name|NDEV
index|]
init|=
block|{
literal|"warp drive"
block|,
literal|"Scotty"
block|,
literal|"S.R. scanners"
block|,
literal|"Scotty"
block|,
literal|"L.R. scanners"
block|,
literal|"Scotty"
block|,
literal|"phasers"
block|,
literal|"Sulu"
block|,
literal|"photon tubes"
block|,
literal|"Sulu"
block|,
literal|"impulse engines"
block|,
literal|"Scotty"
block|,
literal|"shield control"
block|,
literal|"Sulu"
block|,
literal|"computer"
block|,
literal|"Spock"
block|,
literal|"subspace radio"
block|,
literal|"Uhura"
block|,
literal|"life support"
block|,
literal|"Scotty"
block|,
literal|"navigation system"
block|,
literal|"Chekov"
block|,
literal|"cloaking device"
block|,
literal|"Scotty"
block|,
literal|"transporter"
block|,
literal|"Scotty"
block|,
literal|"shuttlecraft"
block|,
literal|"Scotty"
block|,
literal|"*ERR 14*"
block|,
literal|"Nobody"
block|,
literal|"*ERR 15*"
block|,
literal|"Nobody"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Systemname
index|[
name|NINHAB
index|]
init|=
block|{
literal|"ERROR"
block|,
literal|"Talos IV"
block|,
literal|"Rigel III"
block|,
literal|"Deneb VII"
block|,
literal|"Canopus V"
block|,
literal|"Icarus I"
block|,
literal|"Prometheus II"
block|,
literal|"Omega VII"
block|,
literal|"Elysium I"
block|,
literal|"Scalos IV"
block|,
literal|"Procyon IV"
block|,
literal|"Arachnid I"
block|,
literal|"Argo VIII"
block|,
literal|"Triad III"
block|,
literal|"Echo IV"
block|,
literal|"Nimrod III"
block|,
literal|"Nemisis IV"
block|,
literal|"Centarurus I"
block|,
literal|"Kronos III"
block|,
literal|"Spectros V"
block|,
literal|"Beta III"
block|,
literal|"Gamma Tranguli VI"
block|,
literal|"Pyris III"
block|,
literal|"Triachus"
block|,
literal|"Marcus XII"
block|,
literal|"Kaland"
block|,
literal|"Ardana"
block|,
literal|"Stratos"
block|,
literal|"Eden"
block|,
literal|"Arrikis"
block|,
literal|"Epsilon Eridani IV"
block|,
literal|"Exo III"
block|}
decl_stmt|;
end_decl_stmt

end_unit

