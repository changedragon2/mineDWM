/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";    /* similar to blue */
static const char col_olive[]       = "#A3A700";    /* similar to olive green */
static const char col_chartreuse[]  = "#D7FF00";    /* similar to yellow green */
static const char col_orange[]      = "#FA7C04";    /* similar to orange */
static const unsigned int baralpha        = 0xd0;
static const unsigned int borderalpha     = OPAQUE;
static const char *colors[][3]      = {
	/*                    fg              bg                border   */
	[SchemeNorm]      = { col_gray3,      col_gray1,        col_gray2 },
	[SchemeSel]       = { col_gray4,      col_cyan,         col_cyan  },
  [SchemeTagsNorm]  = { col_gray3,      col_gray1,        col_gray2 },
  [SchemeTagsSel]   = { col_gray4,      col_olive,        col_chartreuse },
  [SchemeTitleNorm] = { col_gray3,      col_gray1,        col_gray2 },
  [SchemeTitleSel]  = { col_gray4,      col_orange,       col_orange },
  [SchemeStatus]    = { col_gray3,      col_gray1,        col_gray2 },
};
static const unsigned int alphas[][3] = {
  /*                    fg              bg                border    */
  [SchemeNorm]      = { OPAQUE,         baralpha,         borderalpha },
  [SchemeSel]       = { OPAQUE,         baralpha,         borderalpha },
  [SchemeTagsNorm]  = { OPAQUE,         baralpha,         borderalpha },
  [SchemeTagsSel]   = { OPAQUE,         baralpha,         borderalpha },
  [SchemeTitleNorm] = { OPAQUE,         baralpha,         borderalpha },
  [SchemeTitleSel]  = { OPAQUE,         baralpha,         borderalpha },
  [SchemeStatus]    = { OPAQUE,         baralpha,         borderalpha },
  /* [SchemeStatus]    = { col_gray4,  col_gray1,  col_gray2   }, */
  /* [SchemeTitleNorm] = { OPAQUE, baralpha, borderalpha }, */
  /* [SchemeTitleSel]  = { OPAQUE, baralpha, borderalpha }, */
  /* [SchemeTagsNorm]  = { OPAQUE, baralpha, borderalpha }, */
  /* [SchemeTagsSel]   = { OPAQUE, baralpha, borderalpha }, */
  /* [SchemeHidNorm]   = { OPAQUE, baralpha, borderalpha }, */
  /* [SchemeHidSel]    = { OPAQUE, baralpha, borderalpha }, */
  /* [SchemeUrg]       = { OPAQUE, baralpha, borderalpha }, */
};

/* tagging */
static const char *tags[] = { "乾", "坤", "离", "坎", "兑", "巽", "艮", "震", "卦" };
static const int taglayouts[2][LENGTH(tags)] = {
  { 0, 2, 1, 0, 0, 0, 0, 0, 0 },
  { 2, 0, 0, 1, 1, 1, 1, 1, 2 }
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                            instance    title       tags mask     isfloating    isalwaysontop    monitor */
	{ "Gimp",                             NULL,       NULL,       0,            1,               0,             -1 },
	{ "Firefox",                          NULL,       NULL,       1 << 8,       0,               0,             -1 },
	{ "mpv",                              NULL,       NULL,       0,            1,               1,             -1 },
	{ "obsidian",                         NULL,       NULL,       0,            1,               0,             -1 },
	{ "Nemo",                             NULL,       NULL,       0,            1,               0,             -1 },
	{ "QQ",                               NULL,       NULL,       0,            1,               0,             -1 },
	{ "Telegram-Desktop",                 NULL,       NULL,       0,            1,               0,             -1 },
	{ "Gpick",                            NULL,       NULL,       0,            1,               0,             -1 },
	{ "TelegramDesktop",                  NULL,       NULL,       0,            1,               0,             -1 },
	{ "kitty",                            NULL,       NULL,       0,            1,               0,             -1 },
	/* { "org.wezfurlong.wezterm",           NULL,       NULL,       0,            1,               0,             -1 }, */
	{ "sdlpal-linux",                     NULL,       NULL,       0,            1,               0,             -1 },
	{ "Citra",                            NULL,       NULL,       0,            1,               0,             -1 },
	{ "Sxiv",                             NULL,       NULL,       0,            1,               0,             -1 },
	{ "feh",                              NULL,       NULL,       0,            1,               0,             -1 },
	{ "Qalculate-gtk",                    NULL,       NULL,       0,            1,               0,             -1 },
	{ "xdman",                            NULL,       NULL,       0,            1,               0,             -1 },
	{ "Blueman-manager",                  NULL,       NULL,       0,            1,               0,             -1 },
	{ "copyq",                            NULL,       NULL,       0,            1,               0,             -1 },
	{ "Xmind",                            NULL,       NULL,       0,            1,               0,             -1 },
	{ "KeePassXC",                        NULL,       NULL,       0,            1,               0,             -1 },
	{ "Com.github.xournalpp.xournalpp",   NULL,       NULL,       0,            1,               0,             -1 },
  { "fcitx5-config-qt",                 NULL,       NULL,       0,            1,               0,             -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	/* { "><>",      NULL },    /1* no layout function means floating behavior *1/ */
	{ "<./><",    NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
  { "|M|",      centermaster },
  { "<M>",      centerfloatingmaster },
  { "TTT",      bstack },
  { "===",      bstackhoriz },
};

#include "keysdefine.h"
/* key definitions */
//#define MODKEY Mod1Mask
//#define TAGKEYS(KEY,TAG) \
//	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
//	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
//	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
//	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
//
///* helper for spawning shell commands in the pre dwm-5.0 fashion */
//#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
//
///* commands */
//static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
//static const char *termcmd[]  = { "st", NULL };
//
//static const Key keys[] = {
//	/* modifier                     key        function        argument */
//	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
//	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
//	{ MODKEY,                       XK_b,      togglebar,      {0} },
//	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
//	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
//	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
//	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
//	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
//	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
//	{ MODKEY,                       XK_Return, zoom,           {0} },
//	{ MODKEY,                       XK_Tab,    view,           {0} },
//	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
//	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
//	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
//	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
//	{ MODKEY,                       XK_space,  setlayout,      {0} },
//	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
//	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
//	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
//	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
//	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
//	TAGKEYS(                        XK_1,                      0)
//	TAGKEYS(                        XK_2,                      1)
//	TAGKEYS(                        XK_3,                      2)
//	TAGKEYS(                        XK_4,                      3)
//	TAGKEYS(                        XK_5,                      4)
//	TAGKEYS(                        XK_6,                      5)
//	TAGKEYS(                        XK_7,                      6)
//	TAGKEYS(                        XK_8,                      7)
//	TAGKEYS(                        XK_9,                      8)
//	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
//};
//
///* button definitions */
///* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
//static const Button buttons[] = {
//	/* click                event mask      button          function        argument */
//	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
//	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
//	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
//	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
//	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
//	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
//	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
//	{ ClkTagBar,            0,              Button1,        view,           {0} },
//	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
//	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
//	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
//};
//
