begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * mjs copyright  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * "Plug and Play" functionality.  *  * We use the PnP enumerators to obtain identifiers for installed hardware,  * and the contents of a database to determine modules to be loaded to support  * such hardware.  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<bootstrap.h>
end_include

begin_macro
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|pnpinfo
argument_list|)
end_macro

begin_expr_stmt
name|pnp_devices
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|pnp_devices_initted
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|pnp_discard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Perform complete enumeration sweep  */
end_comment

begin_expr_stmt
name|COMMAND_SET
argument_list|(
name|pnpscan
argument_list|,
literal|"pnpscan"
argument_list|,
literal|"scan for PnP devices"
argument_list|,
name|pnp_scan
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|pnp_scan
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|struct
name|pnpinfo
modifier|*
name|pi
decl_stmt|;
name|int
name|hdlr
decl_stmt|;
name|int
name|verbose
decl_stmt|;
name|int
name|ch
decl_stmt|;
if|if
condition|(
name|pnp_devices_initted
operator|==
literal|0
condition|)
block|{
name|STAILQ_INIT
argument_list|(
operator|&
name|pnp_devices
argument_list|)
expr_stmt|;
name|pnp_devices_initted
operator|=
literal|1
expr_stmt|;
block|}
name|verbose
operator|=
literal|0
expr_stmt|;
name|optind
operator|=
literal|1
expr_stmt|;
name|optreset
operator|=
literal|1
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"v"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'v'
case|:
name|verbose
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
comment|/* getopt has already reported an error */
return|return
operator|(
name|CMD_OK
operator|)
return|;
block|}
block|}
comment|/* forget anything we think we knew */
name|pnp_discard
argument_list|()
expr_stmt|;
comment|/* iterate over all of the handlers */
for|for
control|(
name|hdlr
operator|=
literal|0
init|;
name|pnphandlers
index|[
name|hdlr
index|]
operator|!=
name|NULL
condition|;
name|hdlr
operator|++
control|)
block|{
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"Probing %s...\n"
argument_list|,
name|pnphandlers
index|[
name|hdlr
index|]
operator|->
name|pp_name
argument_list|)
expr_stmt|;
name|pnphandlers
index|[
name|hdlr
index|]
operator|->
name|pp_enumerate
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|verbose
condition|)
block|{
name|pager_open
argument_list|()
expr_stmt|;
name|pager_output
argument_list|(
literal|"PNP scan summary:\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|pi
operator|=
name|pnp_devices
operator|.
name|stqh_first
init|;
name|pi
operator|!=
name|NULL
condition|;
name|pi
operator|=
name|pi
operator|->
name|pi_link
operator|.
name|stqe_next
control|)
block|{
name|pager_output
argument_list|(
name|pi
operator|->
name|pi_ident
operator|.
name|stqh_first
operator|->
name|id_ident
argument_list|)
expr_stmt|;
comment|/* first ident should be canonical */
if|if
condition|(
name|pi
operator|->
name|pi_desc
operator|!=
name|NULL
condition|)
block|{
name|pager_output
argument_list|(
literal|" : "
argument_list|)
expr_stmt|;
name|pager_output
argument_list|(
name|pi
operator|->
name|pi_desc
argument_list|)
expr_stmt|;
block|}
name|pager_output
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|pager_close
argument_list|()
expr_stmt|;
block|}
return|return
operator|(
name|CMD_OK
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Try to load outstanding modules (eg. after disk change)  */
end_comment

begin_comment
unit|COMMAND_SET(pnpload, "pnpload", "load modules for PnP devices", pnp_load);  static int pnp_load(int argc, char *argv[]) {     struct pnpinfo	*pi;     char		*modfname;
comment|/* find anything? */
end_comment

begin_comment
unit|if (pnp_devices.stqh_first != NULL) {
comment|/* check for kernel, assign modules handled by static drivers there */
end_comment

begin_comment
unit|if (pnp_scankernel()) { 	    command_errmsg = "cannot load drivers until kernel loaded"; 	    return(CMD_ERROR); 	} 	if (fname == NULL) {
comment|/* default paths */
end_comment

begin_comment
unit|pnp_readconf("/boot/pnpdata.local"); 	    pnp_readconf("/boot/pnpdata"); 	} else { 	    if (pnp_readconf(fname)) { 		sprintf(command_errbuf, "can't read PnP information from '%s'", fname); 		return(CMD_ERROR); 	    } 	}
comment|/* try to load any modules that have been nominated */
end_comment

begin_comment
unit|for (pi = pnp_devices.stqh_first; pi != NULL; pi = pi->pi_link.stqe_next) {
comment|/* Already loaded? */
end_comment

begin_comment
unit|if ((pi->pi_module != NULL)&& (mod_findmodule(pi->pi_module, NULL) == NULL)) { 		modfname = malloc(strlen(pi->pi_module) + 4); 		sprintf(modfname, "%s.ko", pi->pi_module);
comment|/* XXX implicit knowledge of KLD module filenames */
end_comment

begin_endif
unit|if (mod_load(pi->pi_module, pi->pi_argc, pi->pi_argv)) 		    printf("Could not load module '%s' for device '%s'\n", modfname, pi->pi_ident.stqh_first->id_ident); 		free(modfname); 	    } 	}     }     return(CMD_OK); }
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Throw away anything we think we know about PnP devices.  */
end_comment

begin_function
specifier|static
name|void
name|pnp_discard
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|pnpinfo
modifier|*
name|pi
decl_stmt|;
while|while
condition|(
name|pnp_devices
operator|.
name|stqh_first
operator|!=
name|NULL
condition|)
block|{
name|pi
operator|=
name|pnp_devices
operator|.
name|stqh_first
expr_stmt|;
name|STAILQ_REMOVE_HEAD
argument_list|(
operator|&
name|pnp_devices
argument_list|,
name|pi_link
argument_list|)
expr_stmt|;
name|pnp_freeinfo
argument_list|(
name|pi
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * The PnP configuration database consists of a flat text file with   * entries one per line.  Valid lines are:  *  * #<text>  *  * 	This line is a comment, and ignored.  *  * [<name>]  *  *	Entries following this line are for devices connected to the  *	bus<name>, At least one such entry must be encountered  *	before identifiers are recognised.  *  * ident=<identifier> rev=<revision> module=<module> args=<arguments>  *  *	This line describes an identifier:module mapping.  The 'ident'  *	and 'module' fields are required; the 'rev' field is currently  *	ignored (but should be used), and the 'args' field must come  *	last.  *  * Comments may be appended to lines; any character including or following  * '#' on a line is ignored.  */
end_comment

begin_comment
unit|static int pnp_readconf(char *path) {     struct pnpinfo	*pi;     struct pnpident	*id;     int			fd, line;     char		lbuf[128], *currbus, *ident, *revision, *module, *args;     char		*cp, *ep, *tp, c;
comment|/* try to open the file */
end_comment

begin_comment
unit|if ((fd = open(path, O_RDONLY))>= 0) { 	line = 0; 	currbus = NULL; 	 	while (fgetstr(lbuf, sizeof(lbuf), fd)> 0) { 	    line++;
comment|/* Find the first non-space character on the line */
end_comment

begin_comment
unit|for (cp = lbuf; (*cp != 0)&& !isspace(*cp); cp++) 		;
comment|/* keep/discard? */
end_comment

begin_comment
unit|if ((*cp == 0) || (*cp == '#')) 		continue;
comment|/* cut trailing comment? */
end_comment

begin_comment
unit|if ((ep = strchr(cp, '#')) != NULL) 		*ep = 0;
comment|/* bus declaration? */
end_comment

begin_comment
unit|if (*cp == '[') { 		if (((ep = strchr(cp, ']')) == NULL) || ((ep - cp)< 2)) { 		    printf("%s line %d: bad bus specification\n", path, line); 		} else { 		    if (currbus != NULL) 			free(currbus); 		    *ep = 0; 		    currbus = strdup(cp + 1); 		} 		continue; 	    }
comment|/* XXX should we complain? */
end_comment

begin_comment
unit|if (currbus == NULL) 		continue;
comment|/* mapping */
end_comment

begin_comment
unit|for (ident = module = args = revision = NULL; *cp != 0;) {
comment|/* discard leading whitespace */
end_comment

begin_comment
unit|if (isspace(*cp)) { 		    cp++; 		    continue; 		}
comment|/* scan for terminator, separator */
end_comment

begin_comment
unit|for (ep = cp; (*ep != 0)&& (*ep != '=')&& !isspace(*ep); ep++) 		    ;  		if (*ep == '=') { 		    *ep = 0; 		    for (tp = ep + 1; (*tp != 0)&& !isspace(*tp); tp++) 			; 		    c = *tp; 		    *tp = 0; 		    if ((ident == NULL)&& !strcmp(cp, "ident")) { 			ident = ep + 1; 		    } else if ((revision == NULL)&& !strcmp(cp, "revision")) { 			revision = ep + 1; 		    } else if ((args == NULL)&& !strcmp(cp, "args")) { 			*tp = c; 			while (*tp != 0)
comment|/* skip to end of string */
end_comment

begin_comment
unit|tp++; 			args = ep + 1; 		    } else {
comment|/* XXX complain? */
end_comment

begin_comment
unit|} 		    cp = tp; 		    continue; 		}
comment|/* it's garbage or a keyword - ignore it for now */
end_comment

begin_comment
unit|cp = ep; 	    }
comment|/* we must have at least ident and module set to be interesting */
end_comment

begin_comment
unit|if ((ident == NULL) || (module == NULL)) 		continue;
comment|/* 	     * Loop looking for module/bus that might match this, but aren't already 	     * assigned. 	     * XXX no revision parse/test here yet. 	     */
end_comment

begin_comment
unit|for (pi = pnp_devices.stqh_first; pi != NULL; pi = pi->pi_link.stqe_next) {
comment|/* no driver assigned, bus matches OK */
end_comment

begin_comment
unit|if ((pi->pi_module == NULL)&& 		    !strcmp(pi->pi_handler->pp_name, currbus)) {
comment|/* scan idents, take first match */
end_comment

begin_comment
unit|for (id = pi->pi_ident.stqh_first; id != NULL; id = id->id_link.stqe_next) 			if (!strcmp(id->id_ident, ident)) 			    break;
comment|/* find a match? */
end_comment

begin_endif
unit|if (id != NULL) { 			if (args != NULL) 			    if (parse(&pi->pi_argc,&pi->pi_argv, args)) { 				printf("%s line %d: bad arguments\n", path, line); 				continue; 			    } 			pi->pi_module = strdup(module); 			printf("use module '%s' for %s:%s\n", module, pi->pi_handler->pp_name, id->id_ident); 		    } 		} 	    } 	} 	close(fd);     }     return(CMD_OK); }  static int pnp_scankernel(void) {     return(CMD_OK); }
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Add a unique identifier to (pi)  */
end_comment

begin_function
name|void
name|pnp_addident
parameter_list|(
name|struct
name|pnpinfo
modifier|*
name|pi
parameter_list|,
name|char
modifier|*
name|ident
parameter_list|)
block|{
name|struct
name|pnpident
modifier|*
name|id
decl_stmt|;
for|for
control|(
name|id
operator|=
name|pi
operator|->
name|pi_ident
operator|.
name|stqh_first
init|;
name|id
operator|!=
name|NULL
condition|;
name|id
operator|=
name|id
operator|->
name|id_link
operator|.
name|stqe_next
control|)
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|id
operator|->
name|id_ident
argument_list|,
name|ident
argument_list|)
condition|)
return|return;
comment|/* already have this one */
name|id
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|pnpident
argument_list|)
argument_list|)
expr_stmt|;
name|id
operator|->
name|id_ident
operator|=
name|strdup
argument_list|(
name|ident
argument_list|)
expr_stmt|;
name|STAILQ_INSERT_TAIL
argument_list|(
operator|&
name|pi
operator|->
name|pi_ident
argument_list|,
name|id
argument_list|,
name|id_link
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Allocate a new pnpinfo struct  */
end_comment

begin_function
name|struct
name|pnpinfo
modifier|*
name|pnp_allocinfo
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|pnpinfo
modifier|*
name|pi
decl_stmt|;
name|pi
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|pnpinfo
argument_list|)
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|pi
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pnpinfo
argument_list|)
argument_list|)
expr_stmt|;
name|STAILQ_INIT
argument_list|(
operator|&
name|pi
operator|->
name|pi_ident
argument_list|)
expr_stmt|;
return|return
operator|(
name|pi
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Release storage held by a pnpinfo struct  */
end_comment

begin_function
name|void
name|pnp_freeinfo
parameter_list|(
name|struct
name|pnpinfo
modifier|*
name|pi
parameter_list|)
block|{
name|struct
name|pnpident
modifier|*
name|id
decl_stmt|;
while|while
condition|(
name|pi
operator|->
name|pi_ident
operator|.
name|stqh_first
operator|!=
name|NULL
condition|)
block|{
name|id
operator|=
name|pi
operator|->
name|pi_ident
operator|.
name|stqh_first
expr_stmt|;
name|STAILQ_REMOVE_HEAD
argument_list|(
operator|&
name|pi
operator|->
name|pi_ident
argument_list|,
name|id_link
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|id
operator|->
name|id_ident
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pi
operator|->
name|pi_desc
condition|)
name|free
argument_list|(
name|pi
operator|->
name|pi_desc
argument_list|)
expr_stmt|;
if|if
condition|(
name|pi
operator|->
name|pi_module
condition|)
name|free
argument_list|(
name|pi
operator|->
name|pi_module
argument_list|)
expr_stmt|;
if|if
condition|(
name|pi
operator|->
name|pi_argv
condition|)
name|free
argument_list|(
name|pi
operator|->
name|pi_argv
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|pi
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Add a new pnpinfo struct to the list.  */
end_comment

begin_function
name|void
name|pnp_addinfo
parameter_list|(
name|struct
name|pnpinfo
modifier|*
name|pi
parameter_list|)
block|{
name|STAILQ_INSERT_TAIL
argument_list|(
operator|&
name|pnp_devices
argument_list|,
name|pi
argument_list|,
name|pi_link
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Format an EISA id as a string in standard ISA PnP format, AAAIIRR  * where 'AAA' is the EISA vendor ID, II is the product ID and RR the revision ID.  */
end_comment

begin_function
name|char
modifier|*
name|pnp_eisaformat
parameter_list|(
name|u_int8_t
modifier|*
name|data
parameter_list|)
block|{
specifier|static
name|char
name|idbuf
index|[
literal|8
index|]
decl_stmt|;
specifier|const
name|char
name|hextoascii
index|[]
init|=
literal|"0123456789abcdef"
decl_stmt|;
name|idbuf
index|[
literal|0
index|]
operator|=
literal|'@'
operator|+
operator|(
operator|(
name|data
index|[
literal|0
index|]
operator|&
literal|0x7c
operator|)
operator|>>
literal|2
operator|)
expr_stmt|;
name|idbuf
index|[
literal|1
index|]
operator|=
literal|'@'
operator|+
operator|(
operator|(
operator|(
name|data
index|[
literal|0
index|]
operator|&
literal|0x3
operator|)
operator|<<
literal|3
operator|)
operator|+
operator|(
operator|(
name|data
index|[
literal|1
index|]
operator|&
literal|0xe0
operator|)
operator|>>
literal|5
operator|)
operator|)
expr_stmt|;
name|idbuf
index|[
literal|2
index|]
operator|=
literal|'@'
operator|+
operator|(
name|data
index|[
literal|1
index|]
operator|&
literal|0x1f
operator|)
expr_stmt|;
name|idbuf
index|[
literal|3
index|]
operator|=
name|hextoascii
index|[
operator|(
name|data
index|[
literal|2
index|]
operator|>>
literal|4
operator|)
index|]
expr_stmt|;
name|idbuf
index|[
literal|4
index|]
operator|=
name|hextoascii
index|[
operator|(
name|data
index|[
literal|2
index|]
operator|&
literal|0xf
operator|)
index|]
expr_stmt|;
name|idbuf
index|[
literal|5
index|]
operator|=
name|hextoascii
index|[
operator|(
name|data
index|[
literal|3
index|]
operator|>>
literal|4
operator|)
index|]
expr_stmt|;
name|idbuf
index|[
literal|6
index|]
operator|=
name|hextoascii
index|[
operator|(
name|data
index|[
literal|3
index|]
operator|&
literal|0xf
operator|)
index|]
expr_stmt|;
name|idbuf
index|[
literal|7
index|]
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|idbuf
operator|)
return|;
block|}
end_function

end_unit

