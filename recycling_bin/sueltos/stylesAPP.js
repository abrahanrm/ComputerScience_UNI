import { AmplifyTheme } from "aws-amplify-react-native";

const palette = {
  slate: "#191E62",
  slate2: "#356DAE",
  skyblue: "#4DC1F7",
  white: "#FFFFFF",
  night_blue: "#1B6492",
  blue: "#E7F0FD",
  background: "#ACCBEE",
  dark_blue: "#1D3557",

};

//*************** AuthStyle ***********
const AuthStyle = {
  ...AmplifyTheme,
  container: {
    flex: 1,
    flexDirection: "column",
    alignItems: "center",
    justifyContent: "space-around",
    paddingTop: 20,
    width: "100%",
    backgroundColor: palette.slate2,    
  },
  section: {
    flex: 1,
    width: "100%",
    padding: 30,
  },
  sectionHeader: {
    width: "100%",
    marginBottom: 32,
  },
  sectionHeaderText: {
    color: palette.background,     
    fontSize: 20,
    fontWeight: "500",
  },
  sectionFooter: {
    width: "100%",
    padding: 10,
    flexDirection: "row",
    justifyContent: "space-between",
    marginTop: 15,
    marginBottom: 20,
  },
  sectionFooterLink: {
    fontSize: 14,
    color: palette.white,      
    alignItems: "baseline",
    textAlign: "center",
  },
  navBar: {
    marginTop: 35,
    padding: 15,
    flexDirection: "row",
    justifyContent: "flex-end",
    alignItems: "center",
  },
  navButton: {
    backgroundColor: palette.dark_blue, 
    marginLeft: 12,
    borderRadius: 12,   
  },
  cell: {
    flex: 1,
    width: "50%",
  },
  errorRow: {
    flexDirection: "row",
    justifyContent: "center",
  },
  errorRowText: {
    marginLeft: 10,
  },
  photo: {
    width: "100%",
  },
  album: {
    width: "100%",
  },
  button: {
    backgroundColor: palette.dark_blue,     
    alignItems: "center",
    padding: 16,
  },
  buttonDisabled: {
    backgroundColor: palette.dark_blue,    
    alignItems: "center",
    padding: 16,
  },
  buttonText: {
    color: palette.night_blue,               
    fontSize: 14,
    fontWeight: "600",
  },
  formField: {
    marginBottom: 22,
  },
  input: {
    padding: 16,
    borderWidth: 1,
    borderRadius: 8,   
    borderColor: palette.background,        
  },
  inputLabel: {
    marginBottom: 8,
  },
  phoneContainer: {
    display: "flex",
    flexDirection: "row",
    alignItems: "center",
  },
  phoneInput: {
    flex: 2,
    padding: 16,
    borderWidth: 1,
    borderRadius: 8,     
    borderColor: palette.background,          
  },
  picker: {
    flex: 1,
    height: 44,
  },
  pickerItem: {
    height: 44,
  },
};
//*************** AuthHeaderStyle ***********
const AuthHeaderStyle = {
  logo: {
    alignItems: "center",
    backgroundColor: palette.slate,      
  },
  logoView: {
    marginTop: 10,
    justiftyContent: "center",
    alignItems: "center",
    backgroundColor: palette.slate,     
  }, 
};

//*************** IntroStyle ***********
const IntroStyle = {
  image: {
    width: undefined,
    height: "50%",
    aspectRatio: 1,

    backgroundColor: palette.background,       
  },
  title: {
    color: palette.slate,                
  },
  subtitle: {
    color: palette.night_blue,                
  },
  container: {
    backgroundColor: palette.background,         
  },

  buttonStyle: {
    backgroundColor: palette.slate,             
  },
  containerViewStyle: {
    marginVertical: 10,
    backgroundColor: palette.background,         
  },
  textStyle: { color: palette.night_blue },     
};
//*************** ChatStyle ***********
const ChatStyle = {
  container: {
    flexDirection: "row",
    flexWrap: "wrap",
    backgroundColor: palette.white,        
  },
  button: {
    backgroundColor: palette.slate,            
    alignItems: "center",
    padding: 16,
  },
  indicator: {
    justifyContent: "center",
    alignItems: "center",
  },
  backdrop: {
    backgroundColor: "rgba(0, 0, 0, 0.5)",       
  },

  modalImage: {
    paddingVertical: 10,
    width: "100%",
    height: undefined,
    aspectRatio: 4 / 3,
    borderRadius: 20,
  },
  bubble: {
    right: { backgroundColor: palette.slate },    
  },
};

export { palette, AuthStyle, AuthHeaderStyle, IntroStyle, ChatStyle };
