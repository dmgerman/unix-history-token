begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)externs.c	4.1	(Berkeley)	%G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"trek.h"
end_include

begin_comment
comment|/* **	global variable definitions */
end_comment

begin_struct
struct|struct
name|device
name|Device
index|[
name|NDEV
index|]
block|{
literal|"warp drive"
operator|,
literal|"Scotty"
operator|,
literal|"S.R. scanners"
operator|,
literal|"Scotty"
operator|,
literal|"L.R. scanners"
operator|,
literal|"Scotty"
operator|,
literal|"phasers"
operator|,
literal|"Sulu"
operator|,
literal|"photon tubes"
operator|,
literal|"Sulu"
operator|,
literal|"impulse engines"
operator|,
literal|"Scotty"
operator|,
literal|"shield control"
operator|,
literal|"Sulu"
operator|,
literal|"computer"
operator|,
literal|"Spock"
operator|,
literal|"subspace radio"
operator|,
literal|"Uhura"
operator|,
literal|"life support"
operator|,
literal|"Scotty"
operator|,
literal|"navigation system"
operator|,
literal|"Chekov"
operator|,
literal|"cloaking device"
operator|,
literal|"Scotty"
operator|,
literal|"transporter"
operator|,
literal|"Scotty"
operator|,
literal|"shuttlecraft"
operator|,
literal|"Scotty"
operator|,
literal|"*ERR 14*"
operator|,
literal|"Nobody"
operator|,
literal|"*ERR 15*"
operator|,
literal|"Nobody"
block|}
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
name|Systemname
index|[
name|NINHAB
index|]
block|{
literal|"ERROR"
operator|,
literal|"Talos IV"
operator|,
literal|"Rigel III"
operator|,
literal|"Deneb VII"
operator|,
literal|"Canopus V"
operator|,
literal|"Icarus I"
operator|,
literal|"Prometheus II"
operator|,
literal|"Omega VII"
operator|,
literal|"Elysium I"
operator|,
literal|"Scalos IV"
operator|,
literal|"Procyon IV"
operator|,
literal|"Arachnid I"
operator|,
literal|"Argo VIII"
operator|,
literal|"Triad III"
operator|,
literal|"Echo IV"
operator|,
literal|"Nimrod III"
operator|,
literal|"Nemisis IV"
operator|,
literal|"Centarurus I"
operator|,
literal|"Kronos III"
operator|,
literal|"Spectros V"
operator|,
literal|"Beta III"
operator|,
literal|"Gamma Tranguli VI"
operator|,
literal|"Pyris III"
operator|,
literal|"Triachus"
operator|,
literal|"Marcus XII"
operator|,
literal|"Kaland"
operator|,
literal|"Ardana"
operator|,
literal|"Stratos"
operator|,
literal|"Eden"
operator|,
literal|"Arrikis"
operator|,
literal|"Epsilon Eridani IV"
operator|,
literal|"Exo III"
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

