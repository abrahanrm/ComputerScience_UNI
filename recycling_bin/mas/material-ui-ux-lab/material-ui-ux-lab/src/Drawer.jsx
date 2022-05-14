import React from "react";
import {
  Drawer as MUIDrawer,
  ListItem,
  List,
  ListItemIcon,
  ListItemText
} from "@material-ui/core";
import { makeStyles } from "@material-ui/core/styles";
import InboxIcon from "@material-ui/icons/MoveToInbox";
import MailIcon from "@material-ui/icons/Mail";
import { withRouter } from "react-router-dom";
import AccountBalanceIcon from '@material-ui/icons/AccountBalance';
import ForumIcon from '@material-ui/icons/Forum';
import MenuBookIcon from '@material-ui/icons/MenuBook';

const useStyles = makeStyles({
  drawer: {
    width: "190px"
  }
});

const Drawer = props => {
  const { history } = props;
  const classes = useStyles();
  const itemsList = [
    {
      text: "Cursos",
      icon: <AccountBalanceIcon />,
      onClick: () => history.push("/")
    },
    {
      text: "Tutorias",
      icon: <MailIcon />,
      onClick: () => history.push("/about")
    },
    {
        text: "Reuniones",
        icon: <ForumIcon />,
        onClick: () => history.push("/about")
    },
    {
      text: "Biblioteca",
      icon: <MenuBookIcon />,
      onClick: () => history.push("/contact")
    },
    {
        text: "Evaluaciones",
        icon: <MailIcon  />,
        onClick: () => history.push("/about")
    }
  ];
  return (
    <MUIDrawer variant="permanent" className={classes.drawer}>
      <List>
        {itemsList.map((item, index) => {
          const { text, icon, onClick } = item;
          return (
            <ListItem button key={text} onClick={onClick}>
              {icon && <ListItemIcon>{icon}</ListItemIcon>}
              <ListItemText primary={text} />
            </ListItem>
          );
        })}
      </List>
    </MUIDrawer>
  );
};

export default withRouter(Drawer);