begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	These are machine-configuration dependent 	tables.  To add a machine, be sure to update all 	these tables and to add the "ifdef" entry in "mach.h". 	This file corresponds to the following network:  	Ing70-----------CSVAX		A              B 	  |		 |		|              | 	  |		 |		|              | 	  |		 |		|              | 	  |		 |		|              | 	IngVAX		Cory------------C--------------D------------Q 			 |		|	       |\ 			 |		|	       | \ 			 |		|	       |  \ 			 |		|	       |   \ 	EECS40----------OptVAX		E	      SRC   F 	   		 | 	   		 | 	   		 | 	   		 | 			Image  	The tables must be consistent. 	To be added:  */
end_comment

begin_comment
comment|/* Computer Center A Machine (A) */
end_comment

begin_decl_stmt
name|char
name|configA
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|'c'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center B Machine (B) */
end_comment

begin_decl_stmt
name|char
name|configB
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'d'
block|,
literal|'b'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* u,v,w,x,y */
literal|'d'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center C Machine (C) */
end_comment

begin_decl_stmt
name|char
name|configC
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'a'
block|,
literal|'d'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|'y'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center D Machine (D) */
end_comment

begin_decl_stmt
name|char
name|configD
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'f'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'q'
block|,
literal|000
block|,
literal|'s'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|'c'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center E Machine (E) */
end_comment

begin_decl_stmt
name|char
name|configE
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'e'
block|,
comment|/* a,b,c,d,e */
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'c'
block|,
comment|/* u,v,w,x,y */
literal|'c'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center F Machine (F) */
end_comment

begin_decl_stmt
name|char
name|configF
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* a,b,c,d,e */
literal|'f'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* u,v,w,x,y */
literal|'d'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Project INGRES 11/70 (Ing70) */
end_comment

begin_decl_stmt
name|char
name|configI
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* a,b,c,d,e */
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'i'
block|,
literal|'j'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* u,v,w,x,y */
literal|'v'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Project INGRES VAX (IngVAX) */
end_comment

begin_decl_stmt
name|char
name|configJ
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'i'
block|,
literal|'i'
block|,
literal|'i'
block|,
literal|'i'
block|,
literal|'i'
block|,
comment|/* a,b,c,d,e */
literal|'i'
block|,
literal|000
block|,
literal|000
block|,
literal|'i'
block|,
literal|'j'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'i'
block|,
literal|000
block|,
literal|'i'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'i'
block|,
literal|000
block|,
literal|'i'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'i'
block|,
literal|000
block|,
literal|000
block|,
literal|'i'
block|,
comment|/* u,v,w,x,y */
literal|'i'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sakrison's Image Project 11/40 (Image) */
end_comment

begin_decl_stmt
name|char
name|configM
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* a,b,c,d,e */
literal|'o'
block|,
literal|000
block|,
literal|000
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'o'
block|,
literal|000
block|,
literal|'o'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'o'
block|,
literal|000
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* u,v,w,x,y */
literal|'o'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pfeister - Pollack - Sangiovanni Optimization VAX (OptVAX) */
end_comment

begin_decl_stmt
name|char
name|configO
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* a,b,c,d,e */
literal|'y'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'m'
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|'z'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Computer Center Q Machine (Q) */
end_comment

begin_decl_stmt
name|char
name|configQ
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'q'
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* u,v,w,x,y */
literal|'d'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Survey Research Center 11/40 (SRC) */
end_comment

begin_decl_stmt
name|char
name|configS
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|'d'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'s'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'d'
block|,
comment|/* u,v,w,x,y */
literal|'d'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EECS Research (Fateman - Ernie) VAX (CSVAX) */
end_comment

begin_decl_stmt
name|char
name|configV
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
comment|/* a,b,c,d,e */
literal|'y'
block|,
literal|000
block|,
literal|000
block|,
literal|'i'
block|,
literal|'i'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|'y'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EECS Instructional 11/70 (199 Cory) (Cory) */
end_comment

begin_decl_stmt
name|char
name|configY
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'c'
block|,
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
literal|'v'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'o'
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
literal|'c'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|000
block|,
literal|'y'
block|,
comment|/* u,v,w,x,y */
literal|'o'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EECS Departmental 11/40  (EECS40) */
end_comment

begin_decl_stmt
name|char
name|configZ
index|[]
init|=
block|{
comment|/* to get to i, config[i] */
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* a,b,c,d,e */
literal|'o'
block|,
literal|000
block|,
literal|000
block|,
literal|'o'
block|,
literal|'o'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'o'
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'o'
block|,
literal|000
block|,
literal|'o'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'o'
block|,
literal|000
block|,
literal|000
block|,
literal|'o'
block|,
comment|/* u,v,w,x,y */
literal|'z'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this table is used by netlpr to do lpr w/o an acct    and by net and netdaemon to do pre-emption */
end_comment

begin_comment
comment|/* sub.c uses the table in initdaemon to check machine    type - errormsg may be ignored */
end_comment

begin_decl_stmt
name|char
name|machtype
index|[]
init|=
block|{
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
name|M_CC
block|,
comment|/* a,b,c,d,e */
name|M_CC
block|,
literal|0
block|,
literal|0
block|,
name|M_INGRES
block|,
name|M_INGRES
block|,
comment|/* f,g,h,i,j */
literal|0
block|,
literal|0
block|,
name|M_OTHER
block|,
literal|0
block|,
name|M_VAX
block|,
comment|/* k,l,m,n,o */
literal|0
block|,
name|M_CC
block|,
literal|0
block|,
name|M_SRC
block|,
literal|0
block|,
comment|/* p,q,r,s,t */
literal|0
block|,
name|M_VAX
block|,
literal|0
block|,
literal|0
block|,
name|M_CORY
block|,
comment|/* u,v,w,x,y */
name|M_OTHER
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* z */
end_comment

begin_comment
comment|/* this is basically the default machine for each local machine */
end_comment

begin_decl_stmt
name|char
name|remtable
index|[]
init|=
block|{
literal|'c'
block|,
literal|'d'
block|,
literal|'a'
block|,
literal|'c'
block|,
literal|'c'
block|,
comment|/* a,b,c,d,e */
literal|'d'
block|,
literal|000
block|,
literal|000
block|,
literal|'j'
block|,
literal|'i'
block|,
comment|/* f,g,h,i,j */
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* k,l,m,n,o */
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
literal|'d'
block|,
literal|000
block|,
comment|/* p,q,r,s,t */
literal|000
block|,
literal|'y'
block|,
literal|000
block|,
literal|000
block|,
literal|'v'
block|,
comment|/* u,v,w,x,y */
literal|'i'
block|,
literal|0
comment|/* z */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bad login names */
end_comment

begin_decl_stmt
name|struct
name|bstruct
name|btable
index|[]
init|=
block|{
literal|"op"
block|,
literal|'a'
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this table shows the correspondence between    machine names like 'Cory' and their internal    names, like 'y' */
end_comment

begin_struct
specifier|static
struct|struct
name|tt
block|{
name|char
modifier|*
name|bigname
decl_stmt|;
name|char
name|lname
decl_stmt|;
block|}
name|table
index|[]
init|=
block|{
literal|"A"
block|,
literal|'a'
block|,
literal|"B"
block|,
literal|'b'
block|,
literal|"C"
block|,
literal|'c'
block|,
literal|"D"
block|,
literal|'d'
block|,
literal|"E"
block|,
literal|'e'
block|,
literal|"F"
block|,
literal|'f'
block|,
literal|"CCVAX"
block|,
literal|'f'
block|,
literal|"Ing70"
block|,
literal|'i'
block|,
literal|"Ingres"
block|,
literal|'i'
block|,
literal|"IngVAX"
block|,
literal|'j'
block|,
literal|"Image"
block|,
literal|'m'
block|,
literal|"OptVAX"
block|,
literal|'o'
block|,
literal|"SESM"
block|,
literal|'o'
block|,
literal|"Q"
block|,
literal|'q'
block|,
literal|"SRC"
block|,
literal|'s'
block|,
literal|"CSVAX"
block|,
literal|'v'
block|,
literal|"ucbvax"
block|,
literal|'v'
block|,
literal|"VAX"
block|,
literal|'v'
block|,
literal|"Cory"
block|,
literal|'y'
block|,
literal|"EECS40"
block|,
literal|'z'
block|,
literal|0
block|,
literal|0
block|}
struct|;
end_struct

end_unit

