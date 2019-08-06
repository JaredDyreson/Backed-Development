var names_ = [];
var name_list_ = "";

function submit(){
	var name_ = document.getElementByName("amount_of_emails");
	var current_name_ = name_.value;
	names_.push(current_name_);
	document.getElementByClassName("flex-container").innerHTML = "";
	for(var i = 0; i < names_.length; ++i){
		name_list_ = "<li>"+names_[i]+"</li>"
		document.getElementByClassName("flex-container").innerHTML+=name_list_;
	}
}

function display_contents(){
	var current_name_ = document.getElementByName("amount_of_emails");
	if(current_name_ == "" || current_name_.length == 0){
		return false;
	}
	names_.push(current_name_);
	document.getElementByClassName("flex-container").children[0].innerHTML+="<li>"+names_[names_.length-1]+"</li>";
}
