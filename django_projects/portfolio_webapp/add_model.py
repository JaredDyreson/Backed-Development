#!/usr/bin/env python3.5

from projects.models import Project

starbucks_project_ = Project(
	title="Starbucks Automa",
	description="Auto logging work schedule for the Starbucks Partner Portal",
	technology="Python",
	image="img/starbucks_robot.jpg",
	source_button_link_="https://github.com/JaredDyreson/starbucks_automa_production/"
)

starbucks_project_.save()
