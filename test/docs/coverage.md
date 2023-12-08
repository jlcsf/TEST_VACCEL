<html>
  <head>
    <title>pycobertura report</title>
    <meta charset="UTF-8">
    <style>
/*! normalize.css v3.0.2 | MIT License | git.io/normalize */

/**
 * 1. Set default font family to sans-serif.
 * 2. Prevent iOS text size adjust after orientation change, without disabling
 *    user zoom.
 */

html {
  font-family: sans-serif; /* 1 */
  -ms-text-size-adjust: 100%; /* 2 */
  -webkit-text-size-adjust: 100%; /* 2 */
}

/**
 * Remove default margin.
 */

body {
  margin: 0;
}

/* HTML5 display definitions
   ========================================================================== */

/**
 * Correct `block` display not defined for any HTML5 element in IE 8/9.
 * Correct `block` display not defined for `details` or `summary` in IE 10/11
 * and Firefox.
 * Correct `block` display not defined for `main` in IE 11.
 */

article,
aside,
details,
figcaption,
figure,
footer,
header,
hgroup,
main,
menu,
nav,
section,
summary {
  display: block;
}

/**
 * 1. Correct `inline-block` display not defined in IE 8/9.
 * 2. Normalize vertical alignment of `progress` in Chrome, Firefox, and Opera.
 */

audio,
canvas,
progress,
video {
  display: inline-block; /* 1 */
  vertical-align: baseline; /* 2 */
}

/**
 * Prevent modern browsers from displaying `audio` without controls.
 * Remove excess height in iOS 5 devices.
 */

audio:not([controls]) {
  display: none;
  height: 0;
}

/**
 * Address `[hidden]` styling not present in IE 8/9/10.
 * Hide the `template` element in IE 8/9/11, Safari, and Firefox < 22.
 */

[hidden],
template {
  display: none;
}

/* Links
   ========================================================================== */

/**
 * Remove the gray background color from active links in IE 10.
 */

a {
  background-color: transparent;
}

/**
 * Improve readability when focused and also mouse hovered in all browsers.
 */

a:active,
a:hover {
  outline: 0;
}

/* Text-level semantics
   ========================================================================== */

/**
 * Address styling not present in IE 8/9/10/11, Safari, and Chrome.
 */

abbr[title] {
  border-bottom: 1px dotted;
}

/**
 * Address style set to `bolder` in Firefox 4+, Safari, and Chrome.
 */

b,
strong {
  font-weight: bold;
}

/**
 * Address styling not present in Safari and Chrome.
 */

dfn {
  font-style: italic;
}

/**
 * Address variable `h1` font-size and margin within `section` and `article`
 * contexts in Firefox 4+, Safari, and Chrome.
 */

h1 {
  font-size: 2em;
  margin: 0.67em 0;
}

/**
 * Address styling not present in IE 8/9.
 */

mark {
  background: #ff0;
  color: #000;
}

/**
 * Address inconsistent and variable font size in all browsers.
 */

small {
  font-size: 80%;
}

/**
 * Prevent `sub` and `sup` affecting `line-height` in all browsers.
 */

sub,
sup {
  font-size: 75%;
  line-height: 0;
  position: relative;
  vertical-align: baseline;
}

sup {
  top: -0.5em;
}

sub {
  bottom: -0.25em;
}

/* Embedded content
   ========================================================================== */

/**
 * Remove border when inside `a` element in IE 8/9/10.
 */

img {
  border: 0;
}

/**
 * Correct overflow not hidden in IE 9/10/11.
 */

svg:not(:root) {
  overflow: hidden;
}

/* Grouping content
   ========================================================================== */

/**
 * Address margin not present in IE 8/9 and Safari.
 */

figure {
  margin: 1em 40px;
}

/**
 * Address differences between Firefox and other browsers.
 */

hr {
  -moz-box-sizing: content-box;
  box-sizing: content-box;
  height: 0;
}

/**
 * Contain overflow in all browsers.
 */

pre {
  overflow: auto;
}

/**
 * Address odd `em`-unit font size rendering in all browsers.
 */

code,
kbd,
pre,
samp {
  font-family: monospace, monospace;
  font-size: 1em;
}

/* Forms
   ========================================================================== */

/**
 * Known limitation: by default, Chrome and Safari on OS X allow very limited
 * styling of `select`, unless a `border` property is set.
 */

/**
 * 1. Correct color not being inherited.
 *    Known issue: affects color of disabled elements.
 * 2. Correct font properties not being inherited.
 * 3. Address margins set differently in Firefox 4+, Safari, and Chrome.
 */

button,
input,
optgroup,
select,
textarea {
  color: inherit; /* 1 */
  font: inherit; /* 2 */
  margin: 0; /* 3 */
}

/**
 * Address `overflow` set to `hidden` in IE 8/9/10/11.
 */

button {
  overflow: visible;
}

/**
 * Address inconsistent `text-transform` inheritance for `button` and `select`.
 * All other form control elements do not inherit `text-transform` values.
 * Correct `button` style inheritance in Firefox, IE 8/9/10/11, and Opera.
 * Correct `select` style inheritance in Firefox.
 */

button,
select {
  text-transform: none;
}

/**
 * 1. Avoid the WebKit bug in Android 4.0.* where (2) destroys native `audio`
 *    and `video` controls.
 * 2. Correct inability to style clickable `input` types in iOS.
 * 3. Improve usability and consistency of cursor style between image-type
 *    `input` and others.
 */

button,
html input[type="button"], /* 1 */
input[type="reset"],
input[type="submit"] {
  -webkit-appearance: button; /* 2 */
  cursor: pointer; /* 3 */
}

/**
 * Re-set default cursor for disabled elements.
 */

button[disabled],
html input[disabled] {
  cursor: default;
}

/**
 * Remove inner padding and border in Firefox 4+.
 */

button::-moz-focus-inner,
input::-moz-focus-inner {
  border: 0;
  padding: 0;
}

/**
 * Address Firefox 4+ setting `line-height` on `input` using `!important` in
 * the UA stylesheet.
 */

input {
  line-height: normal;
}

/**
 * It's recommended that you don't attempt to style these elements.
 * Firefox's implementation doesn't respect box-sizing, padding, or width.
 *
 * 1. Address box sizing set to `content-box` in IE 8/9/10.
 * 2. Remove excess padding in IE 8/9/10.
 */

input[type="checkbox"],
input[type="radio"] {
  box-sizing: border-box; /* 1 */
  padding: 0; /* 2 */
}

/**
 * Fix the cursor style for Chrome's increment/decrement buttons. For certain
 * `font-size` values of the `input`, it causes the cursor style of the
 * decrement button to change from `default` to `text`.
 */

input[type="number"]::-webkit-inner-spin-button,
input[type="number"]::-webkit-outer-spin-button {
  height: auto;
}

/**
 * 1. Address `appearance` set to `searchfield` in Safari and Chrome.
 * 2. Address `box-sizing` set to `border-box` in Safari and Chrome
 *    (include `-moz` to future-proof).
 */

input[type="search"] {
  -webkit-appearance: textfield; /* 1 */
  -moz-box-sizing: content-box;
  -webkit-box-sizing: content-box; /* 2 */
  box-sizing: content-box;
}

/**
 * Remove inner padding and search cancel button in Safari and Chrome on OS X.
 * Safari (but not Chrome) clips the cancel button when the search input has
 * padding (and `textfield` appearance).
 */

input[type="search"]::-webkit-search-cancel-button,
input[type="search"]::-webkit-search-decoration {
  -webkit-appearance: none;
}

/**
 * Define consistent border, margin, and padding.
 */

fieldset {
  border: 1px solid #c0c0c0;
  margin: 0 2px;
  padding: 0.35em 0.625em 0.75em;
}

/**
 * 1. Correct `color` not being inherited in IE 8/9/10/11.
 * 2. Remove padding so people aren't caught out if they zero out fieldsets.
 */

legend {
  border: 0; /* 1 */
  padding: 0; /* 2 */
}

/**
 * Remove default vertical scrollbar in IE 8/9/10/11.
 */

textarea {
  overflow: auto;
}

/**
 * Don't inherit the `font-weight` (applied by a rule above).
 * NOTE: the default cannot safely be changed in Chrome and Safari on OS X.
 */

optgroup {
  font-weight: bold;
}

/* Tables
   ========================================================================== */

/**
 * Remove most spacing between table cells.
 */

table {
  border-collapse: collapse;
  border-spacing: 0;
}

td,
th {
  padding: 0;
}
/*
* Skeleton V2.0.4
* Copyright 2014, Dave Gamache
* www.getskeleton.com
* Free to use under the MIT license.
* http://www.opensource.org/licenses/mit-license.php
* 12/29/2014
*/


/* Table of contents
––––––––––––––––––––––––––––––––––––––––––––––––––
- Grid
- Base Styles
- Typography
- Links
- Buttons
- Forms
- Lists
- Code
- Tables
- Spacing
- Utilities
- Clearing
- Media Queries
*/


/* Grid
–––––––––––––––––––––––––––––––––––––––––––––––––– */
.container {
  position: relative;
  width: 100%;
  max-width: 960px;
  margin: 0 auto;
  padding: 0 20px;
  box-sizing: border-box; }
.column,
.columns {
  width: 100%;
  float: left;
  box-sizing: border-box; }

/* For devices larger than 400px */
@media (min-width: 400px) {
  .container {
    width: 85%;
    padding: 0; }
}

/* For devices larger than 550px */
@media (min-width: 550px) {
  .container {
    width: 80%; }
  .column,
  .columns {
    margin-left: 4%; }
  .column:first-child,
  .columns:first-child {
    margin-left: 0; }

  .one.column,
  .one.columns                    { width: 4.66666666667%; }
  .two.columns                    { width: 13.3333333333%; }
  .three.columns                  { width: 22%;            }
  .four.columns                   { width: 30.6666666667%; }
  .five.columns                   { width: 39.3333333333%; }
  .six.columns                    { width: 48%;            }
  .seven.columns                  { width: 56.6666666667%; }
  .eight.columns                  { width: 65.3333333333%; }
  .nine.columns                   { width: 74.0%;          }
  .ten.columns                    { width: 82.6666666667%; }
  .eleven.columns                 { width: 91.3333333333%; }
  .twelve.columns                 { width: 100%; margin-left: 0; }

  .one-third.column               { width: 30.6666666667%; }
  .two-thirds.column              { width: 65.3333333333%; }

  .one-half.column                { width: 48%; }

  /* Offsets */
  .offset-by-one.column,
  .offset-by-one.columns          { margin-left: 8.66666666667%; }
  .offset-by-two.column,
  .offset-by-two.columns          { margin-left: 17.3333333333%; }
  .offset-by-three.column,
  .offset-by-three.columns        { margin-left: 26%;            }
  .offset-by-four.column,
  .offset-by-four.columns         { margin-left: 34.6666666667%; }
  .offset-by-five.column,
  .offset-by-five.columns         { margin-left: 43.3333333333%; }
  .offset-by-six.column,
  .offset-by-six.columns          { margin-left: 52%;            }
  .offset-by-seven.column,
  .offset-by-seven.columns        { margin-left: 60.6666666667%; }
  .offset-by-eight.column,
  .offset-by-eight.columns        { margin-left: 69.3333333333%; }
  .offset-by-nine.column,
  .offset-by-nine.columns         { margin-left: 78.0%;          }
  .offset-by-ten.column,
  .offset-by-ten.columns          { margin-left: 86.6666666667%; }
  .offset-by-eleven.column,
  .offset-by-eleven.columns       { margin-left: 95.3333333333%; }

  .offset-by-one-third.column,
  .offset-by-one-third.columns    { margin-left: 34.6666666667%; }
  .offset-by-two-thirds.column,
  .offset-by-two-thirds.columns   { margin-left: 69.3333333333%; }

  .offset-by-one-half.column,
  .offset-by-one-half.columns     { margin-left: 52%; }

}


/* Base Styles
–––––––––––––––––––––––––––––––––––––––––––––––––– */
/* NOTE
html is set to 62.5% so that all the REM measurements throughout Skeleton
are based on 10px sizing. So basically 1.5rem = 15px :) */
html {
  font-size: 62.5%; }
body {
  font-size: 1.5em; /* currently ems cause chrome bug misinterpreting rems on body element */
  line-height: 1.6;
  font-weight: 400;
  font-family: "Raleway", "HelveticaNeue", "Helvetica Neue", Helvetica, Arial, sans-serif;
  color: #222; }


/* Typography
–––––––––––––––––––––––––––––––––––––––––––––––––– */
h1, h2, h3, h4, h5, h6 {
  margin-top: 0;
  margin-bottom: 2rem;
  font-weight: 300; }
h1 { font-size: 4.0rem; line-height: 1.2;  letter-spacing: -.1rem;}
h2 { font-size: 3.6rem; line-height: 1.25; letter-spacing: -.1rem; }
h3 { font-size: 3.0rem; line-height: 1.3;  letter-spacing: -.1rem; }
h4 { font-size: 2.4rem; line-height: 1.35; letter-spacing: -.08rem; }
h5 { font-size: 1.8rem; line-height: 1.5;  letter-spacing: -.05rem; }
h6 { font-size: 1.5rem; line-height: 1.6;  letter-spacing: 0; }

/* Larger than phablet */
@media (min-width: 550px) {
  h1 { font-size: 5.0rem; }
  h2 { font-size: 4.2rem; }
  h3 { font-size: 3.6rem; }
  h4 { font-size: 3.0rem; }
  h5 { font-size: 2.4rem; }
  h6 { font-size: 1.5rem; }
}

p {
  margin-top: 0; }


/* Links
–––––––––––––––––––––––––––––––––––––––––––––––––– */
a {
  color: #1EAEDB; }
a:hover {
  color: #0FA0CE; }


/* Buttons
–––––––––––––––––––––––––––––––––––––––––––––––––– */
.button,
button,
input[type="submit"],
input[type="reset"],
input[type="button"] {
  display: inline-block;
  height: 38px;
  padding: 0 30px;
  color: #555;
  text-align: center;
  font-size: 11px;
  font-weight: 600;
  line-height: 38px;
  letter-spacing: .1rem;
  text-transform: uppercase;
  text-decoration: none;
  white-space: nowrap;
  background-color: transparent;
  border-radius: 4px;
  border: 1px solid #bbb;
  cursor: pointer;
  box-sizing: border-box; }
.button:hover,
button:hover,
input[type="submit"]:hover,
input[type="reset"]:hover,
input[type="button"]:hover,
.button:focus,
button:focus,
input[type="submit"]:focus,
input[type="reset"]:focus,
input[type="button"]:focus {
  color: #333;
  border-color: #888;
  outline: 0; }
.button.button-primary,
button.button-primary,
input[type="submit"].button-primary,
input[type="reset"].button-primary,
input[type="button"].button-primary {
  color: #FFF;
  background-color: #33C3F0;
  border-color: #33C3F0; }
.button.button-primary:hover,
button.button-primary:hover,
input[type="submit"].button-primary:hover,
input[type="reset"].button-primary:hover,
input[type="button"].button-primary:hover,
.button.button-primary:focus,
button.button-primary:focus,
input[type="submit"].button-primary:focus,
input[type="reset"].button-primary:focus,
input[type="button"].button-primary:focus {
  color: #FFF;
  background-color: #1EAEDB;
  border-color: #1EAEDB; }


/* Forms
–––––––––––––––––––––––––––––––––––––––––––––––––– */
input[type="email"],
input[type="number"],
input[type="search"],
input[type="text"],
input[type="tel"],
input[type="url"],
input[type="password"],
textarea,
select {
  height: 38px;
  padding: 6px 10px; /* The 6px vertically centers text on FF, ignored by Webkit */
  background-color: #fff;
  border: 1px solid #D1D1D1;
  border-radius: 4px;
  box-shadow: none;
  box-sizing: border-box; }
/* Removes awkward default styles on some inputs for iOS */
input[type="email"],
input[type="number"],
input[type="search"],
input[type="text"],
input[type="tel"],
input[type="url"],
input[type="password"],
textarea {
  -webkit-appearance: none;
     -moz-appearance: none;
          appearance: none; }
textarea {
  min-height: 65px;
  padding-top: 6px;
  padding-bottom: 6px; }
input[type="email"]:focus,
input[type="number"]:focus,
input[type="search"]:focus,
input[type="text"]:focus,
input[type="tel"]:focus,
input[type="url"]:focus,
input[type="password"]:focus,
textarea:focus,
select:focus {
  border: 1px solid #33C3F0;
  outline: 0; }
label,
legend {
  display: block;
  margin-bottom: .5rem;
  font-weight: 600; }
fieldset {
  padding: 0;
  border-width: 0; }
input[type="checkbox"],
input[type="radio"] {
  display: inline; }
label > .label-body {
  display: inline-block;
  margin-left: .5rem;
  font-weight: normal; }


/* Lists
–––––––––––––––––––––––––––––––––––––––––––––––––– */
ul {
  list-style: circle inside; }
ol {
  list-style: decimal inside; }
ol, ul {
  padding-left: 0;
  margin-top: 0; }
ul ul,
ul ol,
ol ol,
ol ul {
  margin: 1.5rem 0 1.5rem 3rem;
  font-size: 90%; }
li {
  margin-bottom: 1rem; }


/* Code
–––––––––––––––––––––––––––––––––––––––––––––––––– */
code {
  padding: .2rem .5rem;
  margin: 0 .2rem;
  font-size: 90%;
  white-space: nowrap;
  background: #F1F1F1;
  border: 1px solid #E1E1E1;
  border-radius: 4px; }
pre > code {
  display: block;
  padding: 1rem 1.5rem;
  white-space: pre; }


/* Tables
–––––––––––––––––––––––––––––––––––––––––––––––––– */
th,
td {
  padding: 12px 15px;
  text-align: left;
  border-bottom: 1px solid #E1E1E1; }
th:first-child,
td:first-child {
  padding-left: 0; }
th:last-child,
td:last-child {
  padding-right: 0; }


/* Spacing
–––––––––––––––––––––––––––––––––––––––––––––––––– */
button,
.button {
  margin-bottom: 1rem; }
input,
textarea,
select,
fieldset {
  margin-bottom: 1.5rem; }
pre,
blockquote,
dl,
figure,
table,
p,
ul,
ol,
form {
  margin-bottom: 2.5rem; }


/* Utilities
–––––––––––––––––––––––––––––––––––––––––––––––––– */
.u-full-width {
  width: 100%;
  box-sizing: border-box; }
.u-max-full-width {
  max-width: 100%;
  box-sizing: border-box; }
.u-pull-right {
  float: right; }
.u-pull-left {
  float: left; }


/* Misc
–––––––––––––––––––––––––––––––––––––––––––––––––– */
hr {
  margin-top: 3rem;
  margin-bottom: 3.5rem;
  border-width: 0;
  border-top: 1px solid #E1E1E1; }


/* Clearing
–––––––––––––––––––––––––––––––––––––––––––––––––– */

/* Self Clearing Goodness */
.container:after,
.row:after,
.u-cf {
  content: "";
  display: table;
  clear: both; }


/* Media Queries
–––––––––––––––––––––––––––––––––––––––––––––––––– */
/*
Note: The best way to structure the use of media queries is to create the queries
near the relevant code. For example, if you wanted to change the styles for buttons
on small devices, paste the mobile query code up in the buttons section and style it
there.
*/


/* Larger than mobile */
@media (min-width: 400px) {}

/* Larger than phablet (also point when grid becomes active) */
@media (min-width: 550px) {}

/* Larger than tablet */
@media (min-width: 750px) {}

/* Larger than desktop */
@media (min-width: 1000px) {}

/* Larger than Desktop HD */
@media (min-width: 1200px) {}
.hit {background-color: #EAFFEA}
.miss {background-color: #FFECEC}
.container .code {margin-left: 0}
pre {line-height: 1.3}
    </style>
  </head>
  <body>
    <div class="container">
      <h1>pycobertura report</h1>
      <table class="u-full-width">
        <thead>
          <tr>
            <th>Filename</th>
            <th>Stmts</th>
            <th>Miss</th>
            <th>Cover</th>
            <th>Missing</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td><a href="#src/id_pool.c">src/id_pool.c</a></td>
            <td>34</td>
            <td>4</td>
            <td>88.24%</td>
            <td>27, 65, 68, 75</td>
          </tr>
          <tr>
            <td><a href="#src/list.h">src/list.h</a></td>
            <td>25</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#src/log.c">src/log.c</a></td>
            <td>39</td>
            <td>10</td>
            <td>74.36%</td>
            <td>66-75, 88-91</td>
          </tr>
          <tr>
            <td><a href="#src/misc.c">src/misc.c</a></td>
            <td>6</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#src/plugin.c">src/plugin.c</a></td>
            <td>122</td>
            <td>40</td>
            <td>67.21%</td>
            <td>46-47, 51-52, 56-57, 71-72, 76-77, 86, 89, 98-103, 113, 116, 119, 123, 136-137, 154-155, 159-160, 165-166, 185, 197-198, 202-204, 235-246, 278-279, 284</td>
          </tr>
          <tr>
            <td><a href="#src/resources.c">src/resources.c</a></td>
            <td>94</td>
            <td>23</td>
            <td>75.53%</td>
            <td>46, 59, 74, 83-85, 91, 107, 126, 129, 140-142, 165-166, 175-176, 185-186, 195-197, 202, 206</td>
          </tr>
          <tr>
            <td><a href="#src/session.c">src/session.c</a></td>
            <td>153</td>
            <td>38</td>
            <td>75.16%</td>
            <td>55, 77, 82, 88-89, 126-128, 135, 157, 161, 167-170, 175, 183-185, 191, 197-199, 207, 222, 230-231, 236, 243, 253-264, 273, 281, 298, 306</td>
          </tr>
          <tr>
            <td><a href="#src/utils.c">src/utils.c</a></td>
            <td>34</td>
            <td>12</td>
            <td>64.71%</td>
            <td>33, 55-56, 63-65, 68-70, 76-78</td>
          </tr>
          <tr>
            <td><a href="#src/vaccel.c">src/vaccel.c</a></td>
            <td>99</td>
            <td>36</td>
            <td>63.64%</td>
            <td>42-43, 48-50, 56, 61, 70-72, 81, 88, 101-102, 106-123, 129-130, 135-136, 172-173, 178-179, 184-185</td>
          </tr>
          <tr>
            <td><a href="#src/include/plugin.h">src/include/plugin.h</a></td>
            <td>14</td>
            <td>14</td>
            <td>0.00%</td>
            <td>57-75</td>
          </tr>
          <tr>
            <td><a href="#src/include/ops/vaccel_ops.h">src/include/ops/vaccel_ops.h</a></td>
            <td>2</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#src/ops/blas.c">src/ops/blas.c</a></td>
            <td>28</td>
            <td>21</td>
            <td>25.00%</td>
            <td>34, 50, 55-85</td>
          </tr>
          <tr>
            <td><a href="#src/ops/exec.c">src/ops/exec.c</a></td>
            <td>41</td>
            <td>23</td>
            <td>43.90%</td>
            <td>33, 41, 52, 60, 71-73, 85-116</td>
          </tr>
          <tr>
            <td><a href="#src/ops/fpga.c">src/ops/fpga.c</a></td>
            <td>81</td>
            <td>53</td>
            <td>34.57%</td>
            <td>20, 25-43, 62, 67-86, 104, 109-130, 149, 154-174</td>
          </tr>
          <tr>
            <td><a href="#src/ops/genop.c">src/ops/genop.c</a></td>
            <td>9</td>
            <td>4</td>
            <td>55.56%</td>
            <td>70-71, 76-77</td>
          </tr>
          <tr>
            <td><a href="#src/ops/image.c">src/ops/image.c</a></td>
            <td>58</td>
            <td>7</td>
            <td>87.93%</td>
            <td>35, 45-46, 73-76, 80-83</td>
          </tr>
          <tr>
            <td><a href="#src/ops/minmax.c">src/ops/minmax.c</a></td>
            <td>26</td>
            <td>6</td>
            <td>76.92%</td>
            <td>18, 32, 44-46, 50-52</td>
          </tr>
          <tr>
            <td><a href="#src/ops/noop.c">src/ops/noop.c</a></td>
            <td>16</td>
            <td>10</td>
            <td>37.50%</td>
            <td>27, 35, 40-56</td>
          </tr>
          <tr>
            <td><a href="#src/ops/opencv.c">src/ops/opencv.c</a></td>
            <td>10</td>
            <td>10</td>
            <td>0.00%</td>
            <td>9-43</td>
          </tr>
          <tr>
            <td><a href="#src/ops/tf.c">src/ops/tf.c</a></td>
            <td>150</td>
            <td>111</td>
            <td>26.00%</td>
            <td>32-139, 149, 155-156, 166-229, 244-245, 257-258, 282-283, 297-298, 312-338</td>
          </tr>
          <tr>
            <td><a href="#src/ops/torch.c">src/ops/torch.c</a></td>
            <td>92</td>
            <td>92</td>
            <td>0.00%</td>
            <td>19-261</td>
          </tr>
          <tr>
            <td><a href="#src/profiling/vaccel_prof.c">src/profiling/vaccel_prof.c</a></td>
            <td>205</td>
            <td>193</td>
            <td>5.85%</td>
            <td>30-36, 46-99, 107-120, 128-205, 213-407</td>
          </tr>
          <tr>
            <td><a href="#src/resources/file.c">src/resources/file.c</a></td>
            <td>113</td>
            <td>56</td>
            <td>50.44%</td>
            <td>37, 40-41, 46, 72-73, 77-78, 82-83, 96-97, 102, 125-126, 130-132, 147-150, 155-161, 182, 189, 204, 208, 216-218, 227, 251-295</td>
          </tr>
          <tr>
            <td><a href="#src/resources/shared_object.c">src/resources/shared_object.c</a></td>
            <td>68</td>
            <td>32</td>
            <td>52.94%</td>
            <td>32, 43, 47, 52, 58-62, 69, 73, 78, 83, 87, 93, 99-124, 130, 137, 144-149</td>
          </tr>
          <tr>
            <td><a href="#src/resources/tf_model.c">src/resources/tf_model.c</a></td>
            <td>64</td>
            <td>28</td>
            <td>56.25%</td>
            <td>32, 43, 47, 52, 58-62, 69, 73, 78, 83, 87, 93, 99-106, 111, 118, 125-130</td>
          </tr>
          <tr>
            <td><a href="#src/resources/tf_saved_model.c">src/resources/tf_saved_model.c</a></td>
            <td>180</td>
            <td>77</td>
            <td>57.22%</td>
            <td>36, 48-49, 66, 70-71, 79-80, 100, 125, 128, 131-132, 138-139, 145-146, 152-153, 158-159, 167-186, 202-203, 207-208, 222-231, 246-247, 251-252, 266-275, 290-291, 295-296, 310-319, 337-338, 343-344, 350, 360, 365-366, 371-372, 378, 383, 388, 397-402, 414, 421, 432</td>
          </tr>
          <tr>
            <td><a href="#src/resources/torch_saved_model.c">src/resources/torch_saved_model.c</a></td>
            <td>118</td>
            <td>118</td>
            <td>0.00%</td>
            <td>31-298</td>
          </tr>
          <tr>
            <td><a href="#test/test_blas.cpp">test/test_blas.cpp</a></td>
            <td>25</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_example.cpp">test/test_example.cpp</a></td>
            <td>9</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_exec.cpp">test/test_exec.cpp</a></td>
            <td>122</td>
            <td>23</td>
            <td>81.15%</td>
            <td>47-48, 55-56, 94-95, 102-103, 120-121, 127-128, 134-136, 146-149, 209-210, 226-227</td>
          </tr>
          <tr>
            <td><a href="#test/test_fpga.cpp">test/test_fpga.cpp</a></td>
            <td>79</td>
            <td>1</td>
            <td>98.73%</td>
            <td>30</td>
          </tr>
          <tr>
            <td><a href="#test/test_id_pool.cpp">test/test_id_pool.cpp</a></td>
            <td>47</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_image.cpp">test/test_image.cpp</a></td>
            <td>297</td>
            <td>58</td>
            <td>80.47%</td>
            <td>29-30, 39-40, 46-47, 53-54, 63-67, 98-99, 111-112, 146, 161-162, 173-174, 204-205, 216-217, 247, 261-262, 270-271, 303-304, 314-315, 347, 362-363, 370-371, 403-404, 414-415, 447, 462-463, 470-471, 504-505, 515-516, 548, 563-564, 571-572</td>
          </tr>
          <tr>
            <td><a href="#test/test_log.cpp">test/test_log.cpp</a></td>
            <td>3</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_minmax.cpp">test/test_minmax.cpp</a></td>
            <td>57</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_misc.cpp">test/test_misc.cpp</a></td>
            <td>12</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_noop.cpp">test/test_noop.cpp</a></td>
            <td>8</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_plugin.cpp">test/test_plugin.cpp</a></td>
            <td>4</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_resource.cpp">test/test_resource.cpp</a></td>
            <td>54</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_session.cpp">test/test_session.cpp</a></td>
            <td>95</td>
            <td>1</td>
            <td>98.95%</td>
            <td>19</td>
          </tr>
          <tr>
            <td><a href="#test/test_tf_interference.cpp">test/test_tf_interference.cpp</a></td>
            <td>39</td>
            <td>0</td>
            <td>100.00%</td>
            <td></td>
          </tr>
          <tr>
            <td><a href="#test/test_tf_model.cpp">test/test_tf_model.cpp</a></td>
            <td>55</td>
            <td>11</td>
            <td>80.00%</td>
            <td>28-29, 34-35, 40-42, 50-53</td>
          </tr>
          <tr>
            <td><a href="#test/test_tf_saved_model.cpp">test/test_tf_saved_model.cpp</a></td>
            <td>74</td>
            <td>6</td>
            <td>91.89%</td>
            <td>36-37, 42-43, 50, 67</td>
          </tr>
          <tr>
            <td><a href="#test/test_vaccel.cpp">test/test_vaccel.cpp</a></td>
            <td>81</td>
            <td>35</td>
            <td>56.79%</td>
            <td>51-52, 58-60, 69-78, 91, 100-104, 111-112, 116-133, 139-140, 145-146, 164-166</td>
          </tr>
        </tbody>
        <tfoot>
          <tr>
            <td>TOTAL</td>
            <td>2942</td>
            <td>1153</td>
            <td>60.81%</td>
            <td></td>
          </tr>
        </tfoot>
      </table>
<h4 id="src/id_pool.c">src/id_pool.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/id_pool.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/list.h">src/list.h</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/list.h not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/log.c">src/log.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/log.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/misc.c">src/misc.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/misc.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/plugin.c">src/plugin.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/plugin.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/resources.c">src/resources.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/resources.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/session.c">src/session.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/session.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/utils.c">src/utils.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/utils.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/vaccel.c">src/vaccel.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/vaccel.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/include/plugin.h">src/include/plugin.h</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/include/plugin.h not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/include/ops/vaccel_ops.h">src/include/ops/vaccel_ops.h</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/include/ops/vaccel_ops.h not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/blas.c">src/ops/blas.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/blas.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/exec.c">src/ops/exec.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/exec.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/fpga.c">src/ops/fpga.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/fpga.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/genop.c">src/ops/genop.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/genop.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/image.c">src/ops/image.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/image.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/minmax.c">src/ops/minmax.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/minmax.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/noop.c">src/ops/noop.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/noop.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/opencv.c">src/ops/opencv.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/opencv.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/tf.c">src/ops/tf.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/tf.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/ops/torch.c">src/ops/torch.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/ops/torch.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/profiling/vaccel_prof.c">src/profiling/vaccel_prof.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/profiling/vaccel_prof.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/resources/file.c">src/resources/file.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/resources/file.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/resources/shared_object.c">src/resources/shared_object.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/resources/shared_object.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/resources/tf_model.c">src/resources/tf_model.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/resources/tf_model.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/resources/tf_saved_model.c">src/resources/tf_saved_model.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/resources/tf_saved_model.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="src/resources/torch_saved_model.c">src/resources/torch_saved_model.c</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/src/resources/torch_saved_model.c not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_blas.cpp">test/test_blas.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_blas.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_example.cpp">test/test_example.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_example.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_exec.cpp">test/test_exec.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_exec.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_fpga.cpp">test/test_fpga.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_fpga.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_id_pool.cpp">test/test_id_pool.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_id_pool.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_image.cpp">test/test_image.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_image.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_log.cpp">test/test_log.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_log.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_minmax.cpp">test/test_minmax.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_minmax.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_misc.cpp">test/test_misc.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_misc.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_noop.cpp">test/test_noop.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_noop.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_plugin.cpp">test/test_plugin.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_plugin.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_resource.cpp">test/test_resource.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_resource.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_session.cpp">test/test_session.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_session.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_tf_interference.cpp">test/test_tf_interference.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_tf_interference.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_tf_model.cpp">test/test_tf_model.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_tf_model.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_tf_saved_model.cpp">test/test_tf_saved_model.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_tf_saved_model.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>
<h4 id="test/test_vaccel.cpp">test/test_vaccel.cpp</h4>
<table class="code u-max-full-width">
  <tbody>
    <tr>
      <td class="lineno">
        <pre>0 &nbsp;
</pre>
      </td>
      <td class="source">
        <pre><span class="noop">/home/runner/work/feat_vaccel_testing/feat_vaccel_testing/test/docs/test/test_vaccel.cpp not found</span></pre>
      </td>
    </tr>
  </tbody>
</table>

    </div>
  </body>
</html>