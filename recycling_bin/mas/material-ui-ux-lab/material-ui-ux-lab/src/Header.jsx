import React from "react";
import { AppBar, Toolbar, Typography } from "@material-ui/core";
import AcUnitRoundedIcon from "@material-ui/icons/AcUnitRounded";
import AccountTreeRoundedIcon from '@material-ui/icons/AccountTreeRounded';
import { makeStyles } from "@material-ui/styles";

const useStyles = makeStyles(() => ({
  typographyStyles: {
    flex: 1,
    color: 'white',
    justifyContent: "center",
    alignContent: "center",
    backgroundColor: "black",
  },
  bar: {
    backgroundColor: "black",
  }
}));

const Header = () => {
  const classes = useStyles();

  return (
    <AppBar position="static">
      <Toolbar className={classes.bar}>
        <Typography className={classes.typographyStyles}>
          Classroom
        </Typography>
        <AcUnitRoundedIcon />
        <AccountTreeRoundedIcon/>
      </Toolbar>
    </AppBar>
  );
};

export default Header;
