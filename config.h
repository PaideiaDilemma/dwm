/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "";    /* Polybar tray instance name */
static const char *altbarcmd        = "$HOME/.config/polybar/launch"; /* Alternate bar launch command */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "hack:size=10" };
static const char dmenufont[]       = "hack:size=10";
static const char bg_01[]	    = "#1d1f21";
static const char border_01[]       = "#a54242";
static const char fg_01[]           = "#c5c8c6";
static const char fg_02[]           = "#eeeeee";
static const char yellow_01[]       = "#fb8c00";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { fg_01, bg_01,      fg_01  },
	[SchemeSel]  = { fg_02, yellow_01,  yellow_01  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance    title       tags mask      iscentered    isfloating   monitor */
	{ "Gimp",           NULL,       NULL,       0,            0,            1,           -1 },
	{ "Brave",          NULL,       NULL,       0,       0,            0,           -1 },
        { "Pavucontrol",    NULL,       NULL,       0,            1,            1,           -1 },
        { "Fsearch",        NULL,       NULL,       0,            1,            1,           -1 },
        { "Florence",        NULL,       NULL,       0,            1,            1,           -1 },
        { "Gscreenshot",    NULL,       NULL,       0,            1,            1,           -1 },
        { "Xev",    NULL,       NULL,       0,            1,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
      	{ "[]||",      vtile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-modi", "run,drun", "-show", "drun", NULL };
static const char *launchercmd[] = { "/home/max/.config/rofi/launcher/launcher.sh", NULL };
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bg_01, "-nf", fg_01, "-sb", yellow_01, "-sf", fg_02, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *volupcmd[] = { "/home/max/scripts/volume_ctrl", "up", NULL };
static const char *voldowncmd[] = { "/home/max/scripts/volume_ctrl", "down", NULL };
static const char *mutecmd[] = { "/home/max/scripts/volume_ctrl", "toggle", NULL }; 
static const char *lightupcmd[] = { "brightnessctl", "s", "10%+"};
static const char *lightdowncmd[] = { "brightnessctl", "s", "10%-"};
static const char *monitorcmd[] = { "/home/max/scripts/autorandr/rofi_switcher.sh", NULL };
static const char *searchcmd[] = { "fsearch", NULL };
static const char *lockcmd[] = { "slock", NULL };
static const char *wallpapercmd[] = { "/home/max/scripts/wallrnd/set-wallpaper", NULL };
static const char *savewallcmd[] = { "/home/max/scripts/wallrnd/save_wall", NULL};
static const char *screenshotcmd[] = { "gscreenshot", NULL };
static const char *rangercmd[] = { "st", "-e", "ranger", "/home/max", NULL};
static const char *kconnoncmd[] = { "/home/max/scripts/kdeconnectctl", "on", NULL};
static const char *kconnoffcmd[] = { "/home/max/scripts/kdeconnectctl", "off", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = launchercmd } },
	{ MODKEY|ShiftMask,             XK_Return,  spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = searchcmd} },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = rangercmd} },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          {.v = lockcmd} },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          {.v = wallpapercmd} },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = savewallcmd} },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
        { MODKEY|ControlMask,           XK_k,      spawn,          {.v = kconnoncmd} },
        { MODKEY|ControlMask|ShiftMask, XK_k,      spawn,          {.v = kconnoffcmd} },
        { 0,                            0x1008ff11,spawn,          {.v = voldowncmd} },
        { 0,                            0x1008ff13,spawn,          {.v = volupcmd} },
        { 0,                            0x1008ff12,spawn,          {.v = mutecmd} },
        { 0,                            0x1008ff02,spawn,          {.v = lightupcmd} },
        { 0,                            0x1008ff03,spawn,          {.v = lightdowncmd} },
	{ 0,                            0x1008ff59,spawn,          {.v = monitorcmd} },
	{ 0,                            0x1008ff1b,spawn,          {.v = searchcmd} },
	{ 0,                            0x1008ff5d,spawn,          {.v = screenshotcmd} },
	{ 0,                            0x1008ff4a,spawn,          {.v = rangercmd} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +5 } },
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -5 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +5 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -5 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,      {.i = +5 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,      {.i = -5 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_z,      incrihgaps,     {.i = +5 } },
	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -5 } },
	{ MODKEY|ControlMask,           XK_z,      incrivgaps,     {.i = +5 } },
	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -5 } },
	{ MODKEY|Mod1Mask,              XK_z,      incrohgaps,     {.i = +5 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrohgaps,     {.i = -5 } },
	{ MODKEY|ShiftMask,             XK_z,      incrovgaps,     {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -5 } },
	{ MODKEY|ShiftMask,             XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_v,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
   	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  spawn,               1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

